#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

/* Object with mass and volume
 */
class _Object_Collider_Sphere : public _Object_Collider {
public:
    _Object_Collider_Sphere(float r);

	float radius;
};

CB_END_NAMESPACE