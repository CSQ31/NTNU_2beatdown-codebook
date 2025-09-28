/**
 * Author: Ding Fan
 * Date: 2025-09-28
 * License: CC0
 * Source: Ding, ask him
 * Description:
 * Status: Stress tested
 */
// Winding Number
struct ang { // use acos2(d.y, d.x) + 2*PI*t to represent an angle
    pt d; ll t = 0; // direction and number of full turns
    ang t180() { return { d * (T)(-1), t + half(d) }; }
    ang t360() { return { d, t+1}; }
};
bool operator< (ang a, ang b) {
    return make_tuple(a.t, half(a.d), 0) < make_tuple(b.t, half(b.d), cross(a.d,b.d));
}
int windingNumber(vector<pt>& p, pt a) {
    ang b{p.back()-a}; // start at last vertex
    for (pt d : p) {
        // move to first vertex, second, etc.
        assert(!onSegment(b.d, d-a, {0,0}));
        ang c{d-a, b.t};
        if (b.t180() < c) c.t--;
        if (c.t180() < b) c.t++;
        b = c;
    }
    return b.t;
}