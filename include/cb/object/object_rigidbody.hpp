#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

/* Object with mass
 * Can be spawned as freeform mass
 */
class _Object_Rigidbody : public _Object {
public:
	_Object_Rigidbody(OBJECT_TYPE t = OBJECT_TYPE_NONE);

	bool hasRigidbody;

	/* mass
	 */
	float inverseMass;
	/* moment
	 */
	float inverseMoment;
	/* collision bounce factor
	 */
	float bounce;

	/* world position
	 * this is the center of mass
	 */
	glm::vec3 position;
	/* world rotation
	 */
	glm::quat rotation;
	/* world scale
	 * this value should not change during simulation
	 */
	glm::vec3 scale;

	/* linear velocity
	 */
	glm::vec3 velocity;
	
	/* rotational velocity
	 */
	glm::quat rotVelocity;

	glm::vec3 accel;

	glm::quat torque;
};

CB_END_NAMESPACE