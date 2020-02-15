#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

/* Bounding box
 */
struct Ray {
	glm::vec3 origin;
    glm::vec3 direction;
    float maxd;
};

CB_END_NAMESPACE