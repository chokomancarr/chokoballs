#pragma once
#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

namespace Impl_Object {
    void ApplyForces(pObject, _World*);

    void AddForceAt(pObject, float, const glm::vec3&, const glm::vec3&);
    void AddImpulseAt(pObject, float, const glm::vec3&, const glm::vec3&);
    void AddOffsetAt(pObject, float s, const glm::vec3& p, const glm::vec3& d, float idt);

    void ResolveCollision(pObject, pObject, _World*);
};

CB_END_NAMESPACE