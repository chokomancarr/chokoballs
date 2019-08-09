#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

/* A unique object in the world.
 * 
 */
class Object {
protected:
	Object() {}

public:
	
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