#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

_Object_Rigidbody::_Object_Rigidbody(OBJECT_TYPE t) : _Object(t | OBJECT_TYPE_RIGIDBODY),
		inverseMass(1), inverseMoment(1), bounce(1), position(0), 
		rotation(glm::identity<glm::quat>()), scale(1),
		velocity(0), rotVelocity(glm::identity<glm::quat>()) {}

CB_END_NAMESPACE