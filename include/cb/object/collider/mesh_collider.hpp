#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

class _Collider_Mesh : public _Collider {
public:
    _Collider_Mesh();

    std::vector<glm::vec3> vertices;
    std::vector<glm::ivec3> triangles;
};

CB_END_NAMESPACE