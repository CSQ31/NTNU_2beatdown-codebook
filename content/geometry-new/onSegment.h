/**
 * Author: Ding Fan
 * Date: 2025-09-28
 * License: CC0
 * Source: Ding, ask him
 * Description:
 * Status: Stress tested
 */

bool onSegment(pt a, pt b, pt p) {
    return orient(a,b,p) == 0 && dot(a-p, b-p) <= 0;
}