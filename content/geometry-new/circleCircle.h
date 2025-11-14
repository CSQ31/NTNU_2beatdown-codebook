/**
 * Author: Ding Fan
 * Date: 2025-09-28
 * License: CC0
 * Source: Ding, ask him
 * Description:
 * Status: Stress tested
 */
// T = double
#pragma once

#include "Point.h"
int circleCircle(pt o1, double r1, pt o2, double r2, pair<pt,pt> &
out) {
    pt d=o2-o1;
    double d2=sq(d);
    if (d2 == 0) {
        assert(r1 != r2);
        return 0;
    } // concentric circles
    double pd = (d2 + r1*r1 - r2*r2)/2; // = |O_1P| * d
    double h2 = r1*r1 - pd*pd/d2; // = h^2
    if (h2 >= 0) {
        pt p = o1 + d*pd/d2, h = perp(d)*sqrt(h2/d2);
        out = {p-h, p+h};
    }
    return 1 + sgn(h2);
}