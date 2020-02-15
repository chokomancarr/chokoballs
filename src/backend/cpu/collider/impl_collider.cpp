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

namespace {
	void _CollideSphereTri(const glm::vec3& p, float r, const glm::vec3* vs,
			const glm::ivec3& ti, glm::vec3& op, glm::vec3& on, float& od) {
		const auto& v0 = vs[ti[0]];
		const auto vi = vs[ti[1]] - v0;
		const auto vj = vs[ti[2]] - v0;
		const auto norm = glm::normalize(glm::cross(vi, vj));
		const auto mv = glm::mat3x3(vi, vj, norm);
		const auto imv = glm::inverse(mv);
		const auto pv = imv * (p - v0);
		const auto pv2 = glm::vec3(
			std::min(std::max(pv.x, 0.f), 1.f),
			std::min(std::max(pv.y, 0.f), 1.f),
			0
		);
		const auto cp = mv * pv2 + v0;
		const auto d = cp - p;
		auto cr2 = glm::length2(d);
		if (cr2 > r * r)
			return;
		const auto cr = std::sqrt(cr2);
		const auto dpn = glm::dot(d, norm);
		float depth;
		if (dpn < 0.999f) {
			depth = r - cr;
		}
		else if (dpn > 0.999f) {
			depth = r + cr;
		}
		else {
			const auto adpn = std::abs(dpn);
			const auto rn = adpn * r;
			const auto crn = adpn * cr;
			depth = (dpn < 0) ?
				rn - crn :
				rn + crn;
		}
		on = -norm,
		od = depth * 0.5f,
		op = cp - norm * depth * 0.5f;

		return;
	}
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

Impl_Collider_IMPL(Sphere, Mesh) {
	const auto& ps = c1->position;
	
	const auto vs = c2->vertices.data();

	float mind = -1;
	glm::vec3 minp, minn;
	for (auto& t : c2->triangles) {
		glm::vec3 op, on;
		float od = -1;
		_CollideSphereTri(ps, c1->radius, vs, t, op, on, od);
		if (od > mind) {
			minp = op;
			minn = on;
			mind = od;
		}
	}
	if (mind > -1) {
		addcontact(minn, mind, minp);
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
		regcol2(SPHERE, INFPLANE, Sphere, InfPlane),
		regcol2(SPHERE, MESH, Sphere, Mesh)
	};

	fns.at(hashof(objs[0]->colliderType, objs[1]->colliderType))
		(objs, bk->contacts.data(), bk->numContacts);
}

CB_END_NAMESPACE
