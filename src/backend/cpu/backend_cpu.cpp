#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

void _Backend_CPU::Dispatch(_Backend_CPU* b, _World* w) {
	std::lock_guard<std::mutex> lock(update_mutex);

	for (auto& o : b->bodies) {
		Impl_Object::ApplyForces(o, w);
	}
}

_Backend_CPU::_Backend_CPU() {}

CB_STATUS _Backend_CPU::BeginUpdate(_World* world) {
	bodies.clear();
	bodies.reserve(world->objects.size());
	for (auto& o : world->objects) {
		if (!!(o->type & OBJECT_TYPE_RIGIDBODY)) {
			bodies.push_back((_Object_Rigidbody*)o.data());
		}
	}
	//tree = BVHBuilder::Generate(objects);
	computeThread = std::thread(Dispatch, this, world);
	computeThread.detach();
	return CB_STATUS::OK;
}

CB_STATUS _Backend_CPU::FinishUpdate(_World* world) {
	//computeThread.join();
	return CB_STATUS::OK;
}

CB_END_NAMESPACE