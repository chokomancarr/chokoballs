#pragma once
#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

class CollisionPoint {
public:
    glm::vec3 position;
    glm::vec3 normal;
    _Object* target1, *target2;
};

CB_END_NAMESPACE