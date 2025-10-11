/**
 * Author: SQ
 * Date: Unknown
 * Source: Stanford Notebook
 * Description: Compute Minkowski sum for two convex Polygon, return convex in ccw
 * Status: Tested on excellentengineers
 */
#pragma once

#include "Point.h"
#include "convexHull.h"

v<pt> Minkowski(v<pt> a, v<pt> b) { // |A|,|B|>=3
    a = convexHull(a), b = convexHull(b);
    if(a.empty()) return b;
    if(b.empty()) return a;
    int n = sz(a),m = sz(b);
    v<pt> c;
    a.pb(a[0]);a.pb(a[1]);
    b.pb(b[0]);b.pb(b[1]);
    int i = 0,j = 0;
    while(i < n || j < m){
        c.pb(a[i] + b[j]);
        T cr = cross(a[i + 1] - a[i], b[j + 1] - b[j]);
        if(cr >= 0 && i < sz(a))i++;
        if(cr <= 0 && j < m)j++;
    }
    return c;
}
