#pragma once
#include "chokoballs_internal.hpp"
//#include "bvh/bvh_builder.hpp"
#include "object/impl_object.hpp"

CB_BEGIN_NAMESPACE

class _Backend_CPU : public _Backend_Base {
	std::vector<_Object_Rigidbody*> bodies;
	//	BVHObject tree;

	std::thread computeThread;

	static void Dispatch(_Backend_CPU*, _World*);

public:
	_Backend_CPU();

	CB_STATUS BeginUpdate(_World*) override;

	CB_STATUS FinishUpdate(_World*) override;
};

CB_END_NAMESPACE