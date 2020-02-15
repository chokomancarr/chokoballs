#pragma once
#include "chokoballs_internal.hpp"

CB_BEGIN_NAMESPACE

namespace Impl_BBox {
    bool Intersects(Ray*);
    bool Intersects(BBox*);
};

CB_END_NAMESPACE