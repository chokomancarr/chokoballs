#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

_Object_Collider::_Object_Collider(COLLIDER_TYPE c) : _Object_Rigidbody(OBJECT_TYPE_COLLIDER), colliderType(c) {}

CB_END_NAMESPACE