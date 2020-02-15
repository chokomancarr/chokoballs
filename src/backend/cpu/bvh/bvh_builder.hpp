#pragma once
#include "chokoballs_internal.hpp"
#include "bvh_node.hpp"

CB_BEGIN_NAMESPACE

typedef std::vector<BVHNode> BVHObject;

/* Bounding volume hierarchy builder
 */
class BVHBuilder {
public:
	static BVHObject Generate(const std::vector<pObject>&);
};

CB_END_NAMESPACE