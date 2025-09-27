// line.h
struct line {
    pt v; T c; // use v=(-b, a), c to represent a line ax+by=c, 
    line(pt v, T c) : v(v), c(c) {}
    line(T a, T b, T c) : v({b,-a}), c(c) {} // ax + by = c
    line(pt p, pt q) : v(q-p), c(cross(v,p)) {} // From points P to Q
    
    // These work with T = int
    T side(pt p) { return cross(v,p)-c; } // positive when p is on the left of v
    double dist(pt p) { return abs(side(p)) / abs(v); }
    // distance between p and line, square both sides to prevent the precision error
    bool cmpProj(pt p, pt q) { return dot(v,p) < dot(v,q); } // compare projections
    line translate(pt t) { return {v, c + cross(v,t)}; } // translate by a vector t
    
    // These require T = double
    pt proj(pt p) { return p - perp(v)*side(p)/dot(v,v); }
    pt refl(pt p) { return p - perp(v)*(T)2*side(p)/dot(v,v); } 
}; 

// requires T = double
bool inter(line l1, line l2, pt &out) {
    T d = cross(l1.v, l2.v);
    if (d == 0) return false;
    out = (l2.v*l1.c - l1.v*l2.c) / d;
    return true;
}
line bisector(line l1, line l2, bool interior) {
    assert(cross(l1.v, l2.v) != 0); // l1 and l2 cannot be parallel!
    double sign = interior ? 1 : -1;
    return { l2.v/abs(l2.v) + l1.v/abs(l1.v) * sign, l2.c/abs(l2.v) + l1.c/abs(l1.v) * sign }; 
} 