/**
 * Author: Ding Fan
 * Date: 2025-09-28
 * License: CC0
 * Source: Ding, ask him
 * Description:
 * Status: Stress tested
 */
typedef double T;
typedef complex<T> pt;
#define x real()
#define y imag()
T dot(pt v, pt w) { return (conj(v)*w).x; } // positive when the angle < 90
T cross(pt v, pt w) { return (conj(v)*w).y; }  // positive when vector w is on the left side of v(<180)
T orient(pt a, pt b, pt c) { return cross(b-a,c-a); } // return true when c is on left side of ab
pt perp(pt p) { return {-p.y, p.x}; }
int sgn(T d) { return (T(0) < d) - (d < T(0)); }

// Following functions only work for T double
const long double PI = acos(-1);
pt scale(pt p, double a, pt c=pt{}) { return c + (p-c) * a;}
pt rot(pt p, double a, pt c=pt{}) { return c + (p-c) * polar(1.0, a); }

// given fp = f(p), fq = f(q), return f(r)
pt linearTrans(pt p, pt q, pt r, pt fp, pt fq) { return fp + (r-p) * (fq-fp) / (q-p); }

// return radians of the angle between vector v and w.
// To check whether an angle is greater than 90, use the sign of the dot product instead.
double angle(pt v, pt w) { return acos(clamp(dot(v,w) / abs(v) / abs(w), -1.0, 1.0)); }