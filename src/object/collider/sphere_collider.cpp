#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

_Object_Collider_Sphere::_Object_Collider_Sphere(float r)
	: _Object_Collider(COLLIDER_TYPE::SPHERE), radius(r) {}

CB_END_NAMESPACE