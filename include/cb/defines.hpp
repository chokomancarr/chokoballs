#pragma once

#define CB_VERSION_MAJOR 0
#define CB_VERSION_MINOR 1
#define CB_VERSION_REVISION 0

#define CB_NAMESPACE ChokoBalls
#define CB_NS ::CB_NAMESPACE::

#define CB_BEGIN_NAMESPACE namespace CB_NAMESPACE {
#define CB_END_NAMESPACE }

typedef int CB_STATUS;
#define CB_STATUS_OK 0
#define CB_STATUS_NO_BACKEND 1

#define CB_NOT_IMPLEMENTED\
    throw std::logic_error("Function not implemented!");

#define MAX_LAYER_ID 63
#define LAYER_MASK_TYPE uint64_t

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