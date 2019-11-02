#pragma once
#include "chokoballs_internal.hpp"
#include "bvh/bvh_builder.hpp"

CB_BEGIN_NAMESPACE

class Backend_CPU : public Backend_Base {
	std::vector<pObject> objects;
	BVHObject tree;

	std::thread computeThread;

	static void Dispatch(Backend_CPU&);

public:
	Backend_CPU();

	CB_STATUS BeginUpdate(World* const) override;

	CB_STATUS FinishUpdate(World&) override;
};

CB_END_NAMESPACE