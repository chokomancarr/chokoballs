#pragma once
#include "chokoballs.hpp"
#include "enums/collider_type.hpp"

CB_BEGIN_NAMESPACE

class Object_Collider : public Object_Rigidbody {
protected:
	Object_Collider(COLLIDER_TYPE);

public:
	const COLLIDER_TYPE type;

	/* Axis-aligned bounds of this object.
	 */
	BBox bounds;
};

CB_END_NAMESPACE

#include "collider/plane_collider.hpp"
#include "collider/sphere_collider.hpp"