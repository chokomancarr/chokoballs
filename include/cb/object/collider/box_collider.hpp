#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

class _Collider_Box : public _Collider {
public:
	_Collider_Box(const glm::vec3& r);

	glm::vec3 radius;
};

CB_END_NAMESPACE