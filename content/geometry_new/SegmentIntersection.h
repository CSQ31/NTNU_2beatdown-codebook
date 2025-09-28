/**
 * Author: Ding Fan
 * Date: 2025-09-28
 * License: CC0
 * Source: Ding, ask him
 * Description:
 * Status: Stress tested
 */
// return intersect point if intersect properly
// end points of a line if parrallel
// empty otherwise
struct cmpX {
    bool operator()(pt a, pt b) const { return a.x < b.x; }
};
set<pt, cmpX> segInter(pt a, pt b, pt c, pt d) {
    set<pt, cmpX> s;
    double  oa = orient(c,d,a), ob = orient(c,d,b),
            oc = orient(a,b,c), od = orient(a,b,d);
    // Proper intersection exists iff opposite signs
    if (oa*ob < 0 && oc*od < 0) {
        s.insert( (a*ob - b*oa) / (ob-oa) ); // replace this with {0,0} when use T = int
    } else {
        if ( onSegment(c,d,a) ) s.insert(a);
        if ( onSegment(c,d,b) ) s.insert(b);
        if ( onSegment(a,b,c) ) s.insert(c);
        if ( onSegment(a,b,d) ) s.insert(d);
    }
    return s;
}