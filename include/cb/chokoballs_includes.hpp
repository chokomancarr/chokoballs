#pragma once
#include "defines.hpp"

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtx/quaternion.hpp"

CB_BEGIN_NAMESPACE

typedef glm::mat4 Mat4;
typedef glm::vec3 Vec3;
typedef glm::quat Quat;

class ChokoBalls;

#define CB_OBJECT(nm) class nm; typedef std::shared_ptr<nm> p ## nm;

CB_OBJECT(Object)
CB_OBJECT(Object_Rigidbody)
CB_OBJECT(Object_Collider)
CB_OBJECT(Object_Collider_Plane)

CB_OBJECT(World)

#undef CB_OBJECT

CB_END_NAMESPACE

#include "types/bbox.hpp"

#include "object.hpp"

#include "hierarchy/bvh/bvh_builder.hpp"

#include "world.hpp"