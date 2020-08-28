#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

/* infinite half-space pointing at (0, 0, 1)
 */
class _Collider_InfPlane : public _Collider {
public:
	_Collider_InfPlane();
};

CB_END_NAMESPACE