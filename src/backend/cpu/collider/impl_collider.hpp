#pragma once
#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

class Impl_Collider {
public:
#define colsig(a, b)\
    _Collide ## a ## b (pObject o1, pObject o2, Contact* cc, int& i)
#define defcol(a, b)\
    static void colsig(a, b);\
    static void Collide ## a ## b(pObject* cs, Contact* cc, int& i) {\
        _Collide ## a ## b(cs[0], cs[1], cc, i);\
    }\
    static void Collide ## a ## b ## i(pObject* cs, Contact* cc, int& i) {\
        _Collide ## a ## b(cs[1], cs[0], cc, i);\
    }
    typedef void(*colfn)(pObject*, Contact*, int&);

    defcol(Sphere, Sphere)
    defcol(Sphere, InfPlane)
    defcol(Sphere, Mesh)

#undef defcol
#define Impl_Collider_IMPL(a, b) void Impl_Collider::colsig(a, b) {\
	auto c1 = (_Collider_ ## a *)o1->collider.data();\
	auto c2 = (_Collider_ ## b *)o2->collider.data();

#define End_Impl }

    static void findContacts(
        pObject objs[2],
        _Backend_CPU* bk,
        pWorld world
    );
};

CB_END_NAMESPACE
