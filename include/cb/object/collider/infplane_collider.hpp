#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

/* infinite half-space pointing at (0, 0, 1)
 */
class _Object_Collider_InfPlane : public _Object_Collider {
public:
	_Object_Collider_InfPlane();
};

CB_END_NAMESPACE