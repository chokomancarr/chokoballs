#pragma once
#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

/* Bounding volume hierarchy element
 */
struct BVHNode {
	typedef void(*intfunc)(pObject);

	BVHNode* children[2];
	pObject object;
	BBox box;
	//LAYER_MASK_TYPE mask;

	template <typename T>
	void IntersectWith(T tar, intfunc fn) {
		if (object) {
			fn(object);
		}
		else if (Impl_BBox::Intersects(tar)) {
			for (int a = 0; a < 2; a++) {
				children[a]->IntersectWith(tar, fn);
			}
		}
	}
};

CB_END_NAMESPACE