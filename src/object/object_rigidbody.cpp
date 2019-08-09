#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

Object_Rigidbody::Object_Rigidbody() :
		mass(1), position(0), rotation(glm::identity<Quat>()), scale(1),
		velocity(0), rotVelocity(0) {}

CB_END_NAMESPACE