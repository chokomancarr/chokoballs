#pragma once
#include "chokoballs.hpp"
#include "enums/collider_type.hpp"

CB_BEGIN_NAMESPACE

/* Object with mass and volume
 * Must be spawned as specific collider instance
 */
class _Object_Collider : public _Object_Rigidbody {
protected:
	_Object_Collider(COLLIDER_TYPE);

public:
	const COLLIDER_TYPE colliderType;

	/* Axis-aligned bounds of this object.
	 */
	BBox bounds;
};

CB_END_NAMESPACE

//#include "collider/plane_collider.hpp"
#include "collider/sphere_collider.hpp"