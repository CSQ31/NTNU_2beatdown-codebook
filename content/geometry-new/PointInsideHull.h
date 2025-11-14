/**
 * Author: chilli
 * Date: 2019-05-17
 * License: CC0
 * Source: https://github.com/ngthanhtrung23/ACM_Notebook_new
 * Description: Determine whether a point t lies inside a convex hull (CCW
 * order, with no collinear points). Returns true if point lies within
 * the hull. If strict is true, points on the boundary aren't included.
 * Usage:
 * Status: stress-tested
 * Time: O(\log N)
 */
#pragma once

#include "point.h"
#include "onSegment.h"

bool inHull(const v<pt>& l, pt p, bool strict = true) {
	int a = 1, b = sz(l) - 1, r = !strict;
	if (sz(l) < 3) return r && onSegment(l[0], l.back(), p);
	if (orient(l[0], l[a], l[b]) > 0) swap(a, b);
	if (orient(l[0], l[a], p) >= r || orient(l[0], l[b], p)<= -r)
		return false;
	while (abs(a - b) > 1) {
		int c = (a + b) / 2;
		(orient(l[0], l[c], p) > 0 ? b : a) = c;
	}
	return sgn(orient(l[a], l[b], p)) < r;
}

