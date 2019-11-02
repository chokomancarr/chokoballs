#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

Object_Rigidbody::Object_Rigidbody(OBJECT_TYPE t) : Object(t | OBJECT_TYPE_RIGIDBODY),
		mass(1), position(0), rotation(glm::identity<glm::quat>()), scale(1),
		velocity(0), rotVelocity(0) {}

CB_END_NAMESPACE