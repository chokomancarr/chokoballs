#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

void ContactFinder::Gen(_Backend_CPU* bk, pWorld w) {
    const auto sz = bk->bodies.size();
    pObject bs[2];
    for (size_t a = 0; a < sz-1; a++) {
		if (!bk->bodies[a]->collider) continue;
        bs[0] = bk->bodies[a];
        for (size_t b = a+1; b < sz; b++) {
			if (!bk->bodies[b]->collider) continue;
            bs[1] = bk->bodies[b];
            Impl_Collider::findContacts(bs, bk, w);
        }
    }
}

CB_END_NAMESPACE