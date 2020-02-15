#pragma once
#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

struct Contact {
    pObject_Rigidbody objs[2];
    glm::vec3 pos;
    glm::vec3 normal; //points to 2nd object
    float distance;
};

CB_END_NAMESPACE