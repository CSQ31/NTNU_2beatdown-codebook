/**
 * Author: Unknown
 * Date: 2025-10-27
 * License: Unlicense
 * Source: https://github.com/OmeletWithoutEgg/ckiseki/blob/master/codes/Geometry/ConvexHull.cpp
 * Description:
\\\begin{minipage}{75mm}
Returns a vector of the points of the convex hull in counter-clockwise order. set bound=true to include points on the boundary.
\end{minipage}
\begin{minipage}{15mm}
\vspace{-6mm}
\includegraphics[width=\textwidth]{content/geometry/ConvexHull}
\vspace{-6mm}
\end{minipage}
 * Time: O(n \log n)
 * Status: stress-tested, tested with kattis:convexhull
*/
v<pt> convexHull(v<pt> ps, bool bound) {
    if ( sz(ps) <= 1 ) return ps;
    sort(all(ps), [&](pt& a, pt& b) { return make_pair(a.x, a.y) < make_pair(b.x, b.y); } );
	v<pt> h(2*sz(ps)+1); // sz(ps) + 1 is enough if bound=false
    int t = 0, s = 1;
    for (int _ = 2; _--; s = t--, reverse(all(ps))) for (pt p : ps) {
			while (t > s && orient(p, h[t-1], h[t-2]) >= bound) t--;
			h[t++] = p; 
		}
    return h.resize(t), h;
}
