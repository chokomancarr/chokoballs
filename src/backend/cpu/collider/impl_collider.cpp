#include "chokoballs_internal.hpp"
#include "unordered_map"

CB_BEGIN_NAMESPACE

#define addcontact(n, d, p) {\
	auto& c = cc[i++];\
	c.normal = n;\
	c.distance = d;\
	c.pos = p;\
	c.objs[0] = o1;\
	c.objs[1] = o2;\
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

Impl_Collider_IMPL(Sphere, Sphere)
	const auto dv = o2->position - o1->position;
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
			o1->position + (c1->radius - c.distance) * c.normal
		);
	}
End_Impl

Impl_Collider_IMPL(Sphere, InfPlane)
	const auto& ps = o1->position;
	const auto& pp = o2->position;
	const auto dp = ps - pp;
	const auto pn = o2->rotation * glm::vec3(0, 0, 1);
	const auto v = glm::dot(dp, pn) - c1->radius;
	if (v < 0) {
		addcontact(
			-pn,
			-v / 2,
			ps - pn * (c1->radius - c.distance)
		);
	}
End_Impl

Impl_Collider_IMPL(Sphere, Mesh)
	const auto& ps = o1->position;
	
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
End_Impl


Impl_RayCollider_IMPL(InfPlane)
	const auto& pp = o->position;
	const auto pn = o->rotation * glm::vec3(0, 0, 1);
	const auto dr_n = glm::dot(r.direction, pn);
	if (dr_n < 0) {
		const auto cp_n = glm::dot(r.origin - pp, pn);
		const auto d = -cp_n / dr_n;
		if (d < r.maxd) {
			cc.distance = d;
			cc.position = r.origin + r.direction * d;
			cc.normal = pn;
		}
	}
End_Impl

Impl_RayCollider_IMPL(Sphere)
	const auto& pp = o->position;
	const auto o2p = pp - r.origin;
	const auto d2 = glm::length2(o2p);
	const auto r2 = c->radius * c->radius;
	if (d2 > r2) {
		const auto d1 = std::sqrt(d2);
		const auto cth = glm::dot(r.direction, o2p / d1);
		const float d = d1 * cth - std::sqrt(d2 * (cth * cth - 1) + r2);
		if (d < r.maxd) {
			cc.distance = d;
			cc.position = r.origin + r.direction * d;
			cc.normal = glm::normalize(cc.position - pp);
		}
	}
End_Impl

namespace {
	typedef std::array<Impl_Collider::colfn, ((int)COLLIDER_TYPE::_COUNT)*((int)COLLIDER_TYPE::_COUNT)> collut;

	#define lutid(A, B) ((int)(A) * ((int)COLLIDER_TYPE::_COUNT)) + (int)(B)
	#define regcol(A, a)\
		res[lutid(COLLIDER_TYPE::A, COLLIDER_TYPE::A)] = Impl_Collider::Collide ## a ## a;
	#define regcol2(A, B, a, b)\
		res[lutid(COLLIDER_TYPE::A, COLLIDER_TYPE::B)] = Impl_Collider::Collide ## a ## b;\
		res[lutid(COLLIDER_TYPE::B, COLLIDER_TYPE::A)] = Impl_Collider::Collide ## a ## b ## i
	
	collut _getlut() {
		collut res = {};
		regcol(SPHERE, Sphere);
		regcol2(SPHERE, INFPLANE, Sphere, InfPlane);
		//regcol2(SPHERE, MESH, Sphere, Mesh);
		return res;
	}

#define regcolr(A, a)\
		res[(int)COLLIDER_TYPE::A] = Impl_Collider::CollideRay ## a;

	Impl_Collider::rcollut _getrlut() {
		Impl_Collider::rcollut res = {};
		regcolr(INFPLANE, InfPlane)
		regcolr(SPHERE, Sphere)
		
		return res;
	}
}

auto Impl_Collider::getrcollut() -> rcollut {
	static const auto res = _getrlut();
	return res;
}

void Impl_Collider::findContacts(
		pObject objs[2],
		_Backend_CPU* bk,
		pWorld world) {
	
	static const auto lut = _getlut();

	const auto fn = lut[lutid(objs[0]->collider->colliderType, objs[1]->collider->colliderType)];
	assert(fn);
	fn(objs, bk->contacts.data(), bk->numContacts);
}

CB_END_NAMESPACE
