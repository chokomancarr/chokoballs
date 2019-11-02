#pragma once
#include "chokoballs_internal.hpp"
#include "bvh_element.hpp"

CB_BEGIN_NAMESPACE

typedef std::vector<BVHElement> BVHObject;

/* Bounding volume hierarchy builder
 */
class BVHBuilder {
public:
	static BVHObject Generate(const std::vector<pObject>&);
};

CB_END_NAMESPACE