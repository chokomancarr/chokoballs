#pragma once
#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

namespace Impl_Object {
    void ApplyForces(_Object_Rigidbody*, _World*);

    void ResolveCollision(_Object_Rigidbody*, _Object_Rigidbody*, _World*);
};

CB_END_NAMESPACE