/**
 * Author: Ding Fan
 * Date: Unknown
 * Source:
 * Description: test weather the point is in convex polygon in O(log n) time
 * Usage: poly a(polygon), a.in(p);
 * Status: Tested on excellentengineers
 */
#pragma once

#include "Point.h"
#include "onSegment.h"

struct poly {
    vv<pair<pt,pt>> egs; // left and right
    bool sw;
    poly(v<pt>& a): egs(2) {
        int n = sz(a);
        auto l = min_element(all(a), [&](pt& a, pt& b) { return a.y < b.y; } ) - begin(a);
        auto r = min_element(all(a), [&](pt& a, pt& b) { return a.y > b.y; } ) - begin(a);
        rep(i, l, l+n) egs[i>=r].pb( {a[i%n], a[(i+1)%n]} );
        reverse(all(egs[1]));
    }
    bool crossRay(pt a, pt p, pt q) {
        return ( (q.y >= a.y) - (p.y >= a.y) ) * orient(a,p,q) > 0;
    }
    bool in(pt a, bool strict = true) {
        int nc = 0;
        rep(i, 0, 2) {
            auto it = lower_bound(all(egs[i]), a.y, [&](auto& inv, T val) {
                return max(inv.fi.y, inv.se.y) < val;
            });
            while ( it != egs[i].end() && min(it->fi.y, it->se.y) <= a.y ) {
                if ( onSegment(it->fi, it->se, a) ) return !strict;
                
                if ( i==1 ) nc += crossRay(a, it->se, it->fi);
                else nc += crossRay(a, it->fi, it->se);
                ++it;
            }
        }
        return nc & 1;
    }
};
