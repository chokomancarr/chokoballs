#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

_Object_Collider_Box::_Object_Collider_Box(const glm::vec3& r)
	: _Object_Collider(COLLIDER_TYPE::BOX), radius(r) {}

CB_END_NAMESPACE