#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

void ContactFinder::Gen(_Backend_CPU* bk, pWorld w) {
    const auto sz = bk->bodies.size();
    pObject_Collider bs[2];
    for (size_t a = 0; a < sz-1; a++) {
        bs[0] = (pObject_Collider)bk->bodies[a];
        for (size_t b = a+1; b < sz; b++) {
            bs[1] = (pObject_Collider)bk->bodies[b];
            Impl_Collider::findContacts(bs, bk, w);
        }
    }
}

CB_END_NAMESPACE