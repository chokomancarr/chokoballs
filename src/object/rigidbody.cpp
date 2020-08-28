#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

Rigidbody::Rigidbody() :
	inverseMass(1), inverseMoment(1), bounce(1),
	velocity(0), rotVelocity(glm::identity<glm::quat>()) {}

CB_END_NAMESPACE