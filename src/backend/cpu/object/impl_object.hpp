#pragma once
#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

namespace Impl_Object {
    void ApplyForces(_Object_Rigidbody*, _World*);

    void AddForceAt(_Object_Rigidbody*, float, const glm::vec3&, const glm::vec3&);
    void AddImpulseAt(_Object_Rigidbody*, float, const glm::vec3&, const glm::vec3&);
    void AddOffsetAt(_Object_Rigidbody*, float s, const glm::vec3& p, const glm::vec3& d, float idt);

    void ResolveCollision(_Object_Rigidbody*, _Object_Rigidbody*, _World*);
};

CB_END_NAMESPACE