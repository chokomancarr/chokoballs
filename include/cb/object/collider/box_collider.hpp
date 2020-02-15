#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

class _Object_Collider_Box : public _Object_Collider {
public:
    _Object_Collider_Box(const glm::vec3& r);

	glm::vec3 radius;
};

CB_END_NAMESPACE