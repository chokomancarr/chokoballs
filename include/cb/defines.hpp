#pragma once
#include <cstdint>

#define CB_VERSION_MAJOR 0
#define CB_VERSION_MINOR 1
#define CB_VERSION_REVISION 0

#define CB_NAMESPACE ChokoBalls
#define CB_NS ::CB_NAMESPACE::

#define CB_BEGIN_NAMESPACE namespace CB_NAMESPACE {
#define CB_END_NAMESPACE }

enum CB_STATUS {
	OK = 0,
	BACKEND_NOT_SUPPORTED,
	BACKEND_ERROR,
	DEVICE_ERROR,
	OUT_OF_MEMORY_ERROR
};

#define CB_NOT_IMPLEMENTED\
    throw std::logic_error("Function " __function__ " not implemented!");

typedef uint64_t LAYER_MASK_TYPE;
const uint8_t MAX_LAYER_ID = 63;

#ifdef _MSC_VER
	#pragma warning(disable:4996)
#endif

#if PLATFORM_WIN
	#ifdef BUILD_CHOKOBALLS
		#define CB_EXPORT __declspec(dllexport)
	#else
		#define CB_EXPORT __declspec(dllimport)
	#endif
#else
	#define CB_EXPORT
#endif