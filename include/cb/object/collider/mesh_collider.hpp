#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

class _Object_Collider_Mesh : public _Object_Collider {
public:
    _Object_Collider_Mesh();

    std::vector<glm::vec3> vertices;
    std::vector<glm::ivec3> triangles;
};

CB_END_NAMESPACE