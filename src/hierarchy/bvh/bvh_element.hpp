#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

/* Bounding volume hierarchy element
 */
struct BVHElement {
	int parent;
	int is_leaf;
	int left;
	int right;
	BBox box;
	LAYER_MASK_TYPE mask;
};

CB_END_NAMESPACE