#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

_Collider_Sphere::_Collider_Sphere(float r)
	: _Collider(COLLIDER_TYPE::SPHERE), radius(r) {}

CB_END_NAMESPACE