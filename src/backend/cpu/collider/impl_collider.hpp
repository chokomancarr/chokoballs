#pragma once
#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

namespace Impl_Collider {
#define colsig(a, b)\
    _Collide ## a ## b (pObject_Collider_ ## a c1, pObject_Collider_ ## b c2, Contact* cc, int& i)
#define defcol(a, b)\
    void colsig(a, b);\
    inline void Collide ## a ## b(pObject_Collider* cs, Contact* cc, int& i) {\
        _Collide ## a ## b((pObject_Collider_ ## a)cs[0], (pObject_Collider_ ## b)cs[1], cc, i);\
    }\
    inline void Collide ## a ## b ## i(pObject_Collider* cs, Contact* cc, int& i) {\
        _Collide ## a ## b((pObject_Collider_ ## a)cs[1], (pObject_Collider_ ## b)cs[0], cc, i);\
    }
    typedef void(*colfn)(pObject_Collider*, Contact*, int&);

    defcol(Sphere, Sphere)
    defcol(Sphere, InfPlane)
    defcol(Sphere, Mesh)

#undef defcol
#define Impl_Collider_IMPL(a, b) void Impl_Collider::colsig(a, b)

    void findContacts(
        pObject_Collider objs[2],
        _Backend_CPU* bk,
        pWorld world
    );
};

CB_END_NAMESPACE
