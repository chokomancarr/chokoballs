#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

class Object_Rigidbody : public Object {
protected:
	Object_Rigidbody();

public:
	/* mass
	 */
	float mass;

	/* world position
	 */
	Vec3 position;
	/* world rotation
	 */
	Quat rotation;
	/* world scale
	 * this value should not change during simulation
	 */
	Vec3 scale;

	/* linear velocity
	 */
	Vec3 velocity;
	
	/* rotational velocity
	 */
	Vec3 rotVelocity;
};

CB_END_NAMESPACE