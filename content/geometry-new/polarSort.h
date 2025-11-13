/**
 * Author: Ding Fan
 * Date: 2025-09-28
 * License: CC0
 * Source: Ding, ask him
 * Description:
 * Status: Stress tested
 */
bool half(pt p, pt v) {
    // return 0 when arg(p) is in [v, v+pi) 
    return cross(v,p) < 0 || (cross(v,p) == 0 && dot(v,p) < 0);
}
// return 0 when arg(p) is in [0, pi) 
bool half(pt p) { return p.y < 0 || (p.y == 0 && p.x < 0); }
void polarSort(v<pt> &a, pt s=pt{1, 0}) { 
    sort(all(a), [&](pt v, pt w) { 
        return make_tuple(half(v, s), 0) < make_tuple(half(w, s), cross(v,w)); 
    });
}