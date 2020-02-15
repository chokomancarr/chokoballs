#include "chokoballs_internal.hpp"
#include "unordered_map"

CB_BEGIN_NAMESPACE

#define addcontact(n, d, p) {\
	auto& c = cc[i++];\
	c.normal = n;\
	c.distance = d;\
	c.pos = p;\
	c.objs[0] = c1;\
	c.objs[1] = c2;\
}

Impl_Collider_IMPL(Sphere, Sphere) {
	const auto dv = c2->position - c1->position;
	auto d = glm::length2(dv);
	const auto rr = c1->radius + c2->radius;
	if (d > rr*rr) {
		return;
	}
	else {
		d = std::sqrt(d);
		addcontact(
			dv / d,
			(rr - d) * 0.5f,
			c1->position + (c1->radius - c.distance) * c.normal
		);
	}
}

Impl_Collider_IMPL(Sphere, InfPlane) {
	const auto& ps = c1->position;
	const auto& pp = c2->position;
	const auto pn = c2->rotation * glm::vec3(0, 0, 1);
	const auto off = glm::dot(pp, pn);
	const auto v = glm::dot(ps, pn) - off - c1->radius;
	if (v > 0) {
		addcontact(
			-pn,
			v / 2,
			ps - pn * (c1->radius - c.distance)
		);
	}
}

void Impl_Collider::findContacts(
		pObject_Collider objs[2],
		_Backend_CPU* bk,
		pWorld world) {
	#define hashof(A, B) ((int)(A) << 16) + (int)(B)
	#define regcol(A, B, a, b)\
		{ hashof(COLLIDER_TYPE::A, COLLIDER_TYPE::B), Collide ## a ## b }
	#define regcol2(A, B, a, b)\
		regcol(A, B, a, b),\
		{ hashof(COLLIDER_TYPE::B, COLLIDER_TYPE::A), Collide ## a ## b ## i }
	static const std::unordered_map<int, colfn> fns = {
		regcol(SPHERE, SPHERE, Sphere, Sphere),
		regcol2(SPHERE, INFPLANE, Sphere, InfPlane)
	};

	fns.at(hashof(objs[0]->colliderType, objs[1]->colliderType))
		(objs, bk->contacts.data(), bk->numContacts);
}

CB_END_NAMESPACE
