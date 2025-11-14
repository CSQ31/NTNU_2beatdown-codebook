/**
 * Author: Ding Fan
 * Date: 2025-09-28
 * License: CC0
 * Source: Ding, ask him
 * Description:
 * Status: Stress tested
 */
// check if [PQ] crosses ray from A
// definition: crossing: from y<0 to y>=0
bool crossRay(pt a, pt p, pt q) {
    return ( (q.y >= a.y) - (p.y >= a.y) ) * orient(a,p,q) > 0;
}
// if strict, returns false when A is on the boundary
bool inPoly(vector<pt>& p, pt a, bool strict = true) {
    int nc = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        if (onSegment(p[i], p[(i+1)%n], a)) return !strict;
        nc += crossRay(a, p[i], p[(i+1)%n]);
    }
    return nc & 1; // inside if odd number of crossings
}