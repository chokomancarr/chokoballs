#pragma once
#include "chokoballs.hpp"
#include <mutex>

CB_BEGIN_NAMESPACE

class Backend_Base {
public:
	virtual ~Backend_Base() = default;

	/* Dispatch the compute thread
	 * based on the world contents
	 */
	virtual CB_STATUS BeginUpdate(World* const) = 0;

	/* Finishes the compute thread and
	 * update the world contents
	 */
	virtual CB_STATUS FinishUpdate(World&) = 0;
};

CB_END_NAMESPACE

#include "backend/cpu/backend_cpu.hpp"