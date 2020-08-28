#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

class _Collider_Sphere : public _Collider {
public:
    _Collider_Sphere(float r);

	float radius;
};

CB_END_NAMESPACE