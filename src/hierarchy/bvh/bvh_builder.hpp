#pragma once
#include "chokoballs.hpp"
#include "bvh_element.hpp"

CB_BEGIN_NAMESPACE

typedef std::vector<BVHElement> BVHObject;

/* Bounding volume hierarchy builder
 */
class BVHBuilder {
public:
	static BVHObject Generate(const std::vector<Object> objs);
};

CB_END_NAMESPACE