#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

enum class COLLIDER_TYPE {
	BOX,
	PLANE,
	INFPLANE,
	SPHERE,
	MESH,

	_COUNT
};

CB_END_NAMESPACE