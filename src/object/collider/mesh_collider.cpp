#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

_Object_Collider_Mesh::_Object_Collider_Mesh()
    : _Object_Collider(COLLIDER_TYPE::MESH), vertices({}), triangles({}) {}

CB_END_NAMESPACE