/**
 * Author: Ding Fan
 * Date: 2025-09-28
 * License: CC0
 * Source: Ding, ask him
 * Description:
 * Status: Stress tested
 */
// r2 < 0 for inner tangent
// r2 = 0 to find tangent line through point
int tangents(pt o1, double r1, pt o2, double r2, vector<pair<pt,pt>> &out) {
    pt d = o2-o1;
    double dr = r1-r2, d2 = dot(d,d), h2 = d2-dr*dr;
    if (d2 == 0 || h2 < 0) {assert(h2 != 0); return 0;}
    for (double sign : {-1,1}) {
        pt v = (d*dr+perp(d)*sqrt(h2)*sign)/d2;
        out.push_back({o1 + v*r1, o2 + v*r2});
    }
    return 1 + (h2 > 0);
}