bool onSegment(pt a, pt b, pt p) {
    return orient(a,b,p) == 0 && dot(a-p, b-p) <= 0;
}