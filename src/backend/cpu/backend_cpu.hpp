#pragma once
#include "chokoballs_internal.hpp"
#include "collision/contact.hpp"

CB_BEGIN_NAMESPACE

const int MAX_CONTACT_NUM = 1024;

class _Backend_CPU : public _Backend_Base {
public:
	std::vector<_Object*> bodies;

	std::array<Contact, MAX_CONTACT_NUM> contacts;
	int numContacts;
	//	BVHObject tree;

	std::thread computeThread;

	static void Dispatch(_Backend_CPU*, _World*);

//public:
	_Backend_CPU();

	CB_STATUS BeginUpdate(_World*) override;

	CB_STATUS FinishUpdate(_World*) override;
};

CB_END_NAMESPACE

#include "collision/contact_finder.hpp"

#include "collider/impl_collider.hpp"
#include "collision/impl_bbox.hpp"
#include "collision/impl_collision.hpp"

#include "object/impl_object.hpp"
