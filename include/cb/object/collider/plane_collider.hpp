#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

class Object_Collider_Plane : public Object_Collider {
public:
	Object_Collider_Plane();

	static pObject_Collider_Plane Create() { return std::make_shared<Object_Collider_Plane>(); }
};

CB_END_NAMESPACE

#include "collider/plane_collider.hpp"
#include "collider/sphere_collider.hpp"