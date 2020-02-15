#include "bvh_builder.hpp"

CB_BEGIN_NAMESPACE

namespace {
	std::vector<pObject> mortonSort(const std::vector<pObject>& oo) {
		struct st {
			uint64_t code;
			pObject obj;
		};
		const uint64_t maxi = (1 << 20) - 1;
		const auto sz = oo.size();
		std::vector<st> stv(sz);
		for (int a = 0; a < sz; a++) {
			const auto& o = oo[a];
		}
	}
}

BVHObject BVHBuilder::Generate(const std::vector<pObject>& _objs) {
	const auto sz = _objs.size();
	BVHObject res(sz);
	int off = 1;
	
//	auto objs = mortonSort(_objs);

	

	return res;
}

CB_END_NAMESPACE