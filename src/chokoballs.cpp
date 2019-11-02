#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

BACKEND_TYPE ChokoBalls::backendType = BACKEND_TYPE::CPU;

pBackend_Base ChokoBalls::backend = nullptr;

void ChokoBalls::SetBackend(BACKEND_TYPE t) {
	if (!backend)
		backendType = t;
}

CB_STATUS ChokoBalls::Init() {
	switch (backendType) {
	case BACKEND_TYPE::CPU:
		backend = std::make_shared<Backend_CPU>();
		break;
	default:
		return CB_STATUS::BACKEND_NOT_SUPPORTED;
	}

	return CB_STATUS::OK;
}



CB_END_NAMESPACE