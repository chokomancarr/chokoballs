#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

_Collider_Mesh::_Collider_Mesh()
    : _Collider(COLLIDER_TYPE::MESH), vertices({}), triangles({}) {}

CB_END_NAMESPACE