#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

/* Bounding box
 */
struct RayHit {
	glm::vec3 position;
    glm::vec3 normal;
	float distance;
	Object target;
};

CB_END_NAMESPACE