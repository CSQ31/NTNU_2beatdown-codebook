/**
 * Author: Oleksandr Bacherikov, chilli
 * Date: 2019-05-05
 * License: Boost Software License
 * Source: https://codeforces.com/blog/entry/48868
 * Description: Returns the two points with max distance on a convex hull (ccw,
 * no duplicate/collinear points).
 * Status: stress-tested, tested on kattis:roberthood
 * Time: O(n)
 */
#pragma once
#include "point.h"

array<pt, 2> hullDiameter(v<pt> S) {
	int n = sz(S), j = n < 2 ? 0 : 1;
	ll mx=0;
	array<pt, 2> res = {S[0], S[0]};
	rep(i,0,j) for (;; j = (j + 1) % n) {
		if ( dot(S[i]-S[j],S[i]-S[j]) > mx ) {
			mx = dot(S[i]-S[j],S[i]-S[j]);
			res = {S[i], S[j]};
		}
		if ( cross(S[(j+1)%n]-S[j], S[i+1]-S[i]) >= 0 ) break;
	}
	return res;
}
