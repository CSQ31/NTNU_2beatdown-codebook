// return the number of interestions
int circleline(pt o, double r, line l, pair<pt,pt> &out) {
    double h2 = r*r - l.dist(o)*l.dist(o);
    if (h2 >= 0) { // the line touches the circle
        pt p = l.proj(o); // point P
        pt h = l.v*sqrt(h2)/abs(l.v); // vector parallel to l, of length h
        out = {p-h, p+h};
    }
    return 1 + sgn(h2);
}
