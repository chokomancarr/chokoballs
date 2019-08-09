#pragma once
#include "chokoballs.hpp"

CB_BEGIN_NAMESPACE

/* Bounding box
 */
struct BBox {
	float x0, x1,
		y0, y1,
		z0, z1;

	BBox ToAABB(const BBox&, const Mat4&);
};

CB_END_NAMESPACE