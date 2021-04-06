#include "chokoballs_internal.hpp"
#include <condition_variable>

CB_BEGIN_NAMESPACE

#define ARGS _Backend_CPU* b, _World* w
#define vARGS b, w

namespace {
	std::condition_variable condvar;

	void updateforces(ARGS) {
		for (auto& o : b->bodies) {
			if (o->has_rigidbody && o->dynamic) {
				o->rigidbody.accel = glm::vec3(0, w->gravity, 0);
			}
		}
	}

	void movebodies(ARGS) {
		for (auto& o : b->bodies) {
			if (o->has_rigidbody && o->dynamic)
				Impl_Object::ApplyForces(o, w);
		}
	}

	void findcontacts(ARGS) {
		b->numContacts = 0;
		ContactFinder::Gen(vARGS);

		for (int a = 0; a < b->numContacts; a++) {
			auto& c = b->contacts[a];
			auto& co1 = c.objs[0];
			auto& co2 = c.objs[1];
			
			#define p3(v) "(" + std::to_string(v.x) + ", " +\
				std::to_string(v.y) + ", " + std::to_string(v.z) + ")"
			std::cout << "Contact at " << p3(c.pos) << " -> " << p3(c.normal)
				<< " @ " << std::to_string(c.distance) << std::endl;
			std::cout << "  with: " << p3(co1->position) << p3(co2->position) << std::endl;
		}
	}

	void resolvecontacts(ARGS) {
		const float idt = 1.f / w->deltaTime / w->timeScale;
		for (int a = 0; a < b->numContacts; a++) {
			auto& c = b->contacts[a];

			auto& co1 = c.objs[0];
			auto& co2 = c.objs[1];

			const auto im1 = (co1->has_rigidbody && co1->dynamic) ?
				co1->rigidbody.inverseMass : 0;
			const auto im2 = (co2->has_rigidbody && co2->dynamic) ?
				co2->rigidbody.inverseMass : 0;
			const auto im = im1 + im2;
			if (im == 0) continue;

			const auto closingVel1 = glm::dot(c.normal, 
				im1 > 0 ? co1->rigidbody.velocity : glm::vec3(0.f));
			const auto closingVel2 = glm::dot(-c.normal,
				im2 > 0 ? co2->rigidbody.velocity : glm::vec3(0.f));
			const auto closingVel = closingVel1 + closingVel2;
			if (closingVel < 0) continue;

			const auto dm1 = im1 / im;
			const auto dm2 = im2 / im;

			const auto bounce = std::max(
				(co1->has_rigidbody && co1->dynamic) ? co1->rigidbody.bounce : 0,
				(co2->has_rigidbody && co2->dynamic) ? co2->rigidbody.bounce : 0);

			if (im1 > 0) {
				Impl_Object::AddOffsetAt(c.objs[0], c.distance * dm1 * 2, c.pos, -c.normal, idt);
				co1->rigidbody.velocity -= c.normal * closingVel1 - c.normal * bounce *
					((dm2-dm1)*closingVel1 + 2*dm1*closingVel2);
			}
			if (im2 > 0) {
				Impl_Object::AddOffsetAt(c.objs[1], c.distance * dm2 * 2, c.pos, c.normal, idt);
				co2->rigidbody.velocity += c.normal * closingVel2 + c.normal * bounce *
					(2*dm1*closingVel1 + (dm1-dm2)*closingVel2);
			}
		}
	}
}

_Backend_CPU::~_Backend_CPU() {
	if (computeThread.joinable()) {
		computeThread.join();
	}
}

void _Backend_CPU::Dispatch(ARGS) {
	while (1) {
		std::unique_lock<std::mutex> lock(update_mutex);
		condvar.wait(lock);

		updateforces(vARGS);
		movebodies(vARGS);
		findcontacts(vARGS);
		resolvecontacts(vARGS);
	}
}

_Backend_CPU::_Backend_CPU() {}

CB_STATUS _Backend_CPU::BeginUpdate(_World* world) {
	{
		std::unique_lock<std::mutex> lock(update_mutex);
		bodies.clear();
		bodies.reserve(world->objects.size());
		for (auto& o : world->objects) {
			//if (o->has_rigidbody) {
				bodies.push_back(o.data());
			//}
		}
		//tree = BVHBuilder::Generate(objects);
	}
	if (!computeThread.joinable()) {
		std::cout << "starting compute thread" << std::endl;
		computeThread = std::thread(Dispatch, this, world);
	}
	condvar.notify_one();
	return CB_STATUS::OK;
}

CB_STATUS _Backend_CPU::FinishUpdate(_World* world) {
	std::unique_lock<std::mutex> lock(update_mutex);
	return CB_STATUS::OK;
}

CB_STATUS _Backend_CPU::Raycast(_World* world, const Ray& ray, const uint64_t mask, RayHit& result) {
	const auto& lut = Impl_Collider::getrcollut();
	RayHit con = {};
	for (auto& o : world->objects) {
		const auto fn = lut[(int)(o->collider->colliderType)];
		assert(fn);
		fn(ray, o.data(), con);
	}


}

CB_END_NAMESPACE