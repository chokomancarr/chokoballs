#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

class Object_Rigidbody : public Object {
public:
	Object_Rigidbody(OBJECT_TYPE t = OBJECT_TYPE_NONE);

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
};

CB_END_NAMESPACE