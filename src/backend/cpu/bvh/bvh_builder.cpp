#include "bvh_builder.hpp"

CB_BEGIN_NAMESPACE

BVHObject BVHBuilder::Generate(const std::vector<pObject>& objs) {
	//
	BVHObject res(objs.size());
	for (int a = 0; a < objs.size(); a++) {
		auto& r = res[a];
		r.is_leaf = true;
		r.left = a;
		r.left = -1;
	}
	return res;
}

CB_END_NAMESPACE