#pragma once
#include "defines.hpp"

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/gtx/quaternion.hpp"

#include "ext/ptrref.hpp"

CB_BEGIN_NAMESPACE

class ChokoBalls;

#define CB_OBJECT(nm)\
    class _ ## nm;\
    typedef Ref<_ ## nm> nm;\
    typedef _ ## nm* p ## nm;

CB_OBJECT(Backend_Base)

CB_OBJECT(Object)
CB_OBJECT(Object_Rigidbody)
CB_OBJECT(Object_Collider)
CB_OBJECT(Object_Collider_Cube)
CB_OBJECT(Object_Collider_InfPlane)
CB_OBJECT(Object_Collider_Mesh)
CB_OBJECT(Object_Collider_Plane)
CB_OBJECT(Object_Collider_Sphere)

CB_OBJECT(World)

#undef CB_OBJECT

CB_END_NAMESPACE

#include "types/bbox.hpp"
#include "types/ray.hpp"

#include "object.hpp"

//#include "hierarchy/bvh/bvh_builder.hpp"

#include "world.hpp"