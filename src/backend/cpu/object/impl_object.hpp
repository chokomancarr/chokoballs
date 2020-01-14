#pragma once
#include "src/backend/cpu/backend_cpu.hpp"

CB_BEGIN_NAMESPACE

namespace Impl_Object {
    void ApplyForces(const _Object_Rigidbody*);
};

CB_END_NAMESPACE