#pragma once
#include "chokoballs.hpp"
#include "enums/object_type.hpp"

CB_BEGIN_NAMESPACE

/* A unique object in the world.
 * 
 */
class Object {
protected:
	Object(OBJECT_TYPE t) : type(t) {}

public:
	
	const OBJECT_TYPE type;

	/* Is this object affected by physics updates?
	 */
	bool dynamic = true;

	/* Layer ID of this object
	 */
	uint8_t layer_id = 0;

	/* Only objects with these layer IDs will affect / be affected by this object
	 */
	uint64_t layer_mask = ~0Ui64;
};

CB_END_NAMESPACE

#include "object/object_rigidbody.hpp"
#include "object/object_collider.hpp"