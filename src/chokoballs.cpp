#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

std::mutex update_mutex;


BACKEND_TYPE ChokoBalls::backendType = BACKEND_TYPE::CPU;

Backend_Base ChokoBalls::backend = nullptr;

void ChokoBalls::SetBackend(BACKEND_TYPE t) {
	if (!backend)
		backendType = t;
}

CB_STATUS ChokoBalls::Init() {
	switch (backendType) {
	case BACKEND_TYPE::CPU:
		backend = Ref<_Backend_CPU>::New();
		break;
	default:
		return CB_STATUS::BACKEND_NOT_SUPPORTED;
	}

	return CB_STATUS::OK;
}



CB_END_NAMESPACE