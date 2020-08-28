#pragma once
#include "chokoballs.hpp"
#include "object/rigidbody.hpp"

CB_BEGIN_NAMESPACE

/* An unique object in the world.
 * 
 */
class _Object {
public:
	glm::vec3 position;
	glm::quat rotation;
	glm::vec3 scale;

	bool has_rigidbody = false;
	Rigidbody rigidbody = {};
	Collider collider = nullptr;

	/* Is this object affected by physics updates?
	 */
	bool dynamic = true;

	/* Layer ID of this object
	 */
	uint8_t layer_id = 0;

	/* Only objects with these layer IDs will affect / be affected by this object
	 */
	uint64_t layer_mask = ~uint64_t(0);
};

CB_END_NAMESPACE

#include "object/collider.hpp"