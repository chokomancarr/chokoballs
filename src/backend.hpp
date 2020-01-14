#pragma once
#include "chokoballs.hpp"
#include <mutex>

CB_BEGIN_NAMESPACE

class _Backend_Base {
public:
	virtual ~_Backend_Base() = default;

	/* Dispatch the compute thread
	 * based on the world contents
	 */
	virtual CB_STATUS BeginUpdate(_World*) = 0;

	/* Finishes the compute thread and
	 * update the world contents
	 */
	virtual CB_STATUS FinishUpdate(_World*) = 0;
};

CB_END_NAMESPACE

#include "backend/cpu/backend_cpu.hpp"