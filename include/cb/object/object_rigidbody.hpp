#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

/* Object with mass
 * Can be spawned as freeform mass
 */
class _Object_Rigidbody : public _Object {
public:
	_Object_Rigidbody(OBJECT_TYPE t = OBJECT_TYPE_NONE);

	/* mass
	 */
	float mass;

	/* world position
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
	glm::vec3 rotVelocity;

	glm::vec3 force;

	glm::vec3 torque;
};

CB_END_NAMESPACE