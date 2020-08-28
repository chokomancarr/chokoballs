#pragma once
#include "chokoballs.hpp"
#include "enums/collider_type.hpp"

CB_BEGIN_NAMESPACE

/* Object with mass and volume
 * Must be spawned as specific collider instance
 */
class _Collider {
protected:
	_Collider(COLLIDER_TYPE);

public:
	virtual ~_Collider() = default;

	const COLLIDER_TYPE colliderType;

	/* Axis-aligned bounds of this object.
	 */
	BBox bounds;
};

CB_END_NAMESPACE

#include "collider/box_collider.hpp"
#include "collider/infplane_collider.hpp"
#include "collider/mesh_collider.hpp"
//#include "collider/plane_collider.hpp"
#include "collider/sphere_collider.hpp"