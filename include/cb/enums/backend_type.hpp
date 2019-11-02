#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

enum class BACKEND_TYPE {
	CPU,
    OPENCL,

    /* TODO: implement these
    GLSL,
    CUDA,
	etc
    */
};

CB_END_NAMESPACE