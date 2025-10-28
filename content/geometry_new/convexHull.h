/**
 * Author: Stjepan Glavina, chilli
 * Date: 2019-05-05
 * License: Unlicense
 * Source: https://github.com/stjepang/snippets/blob/master/convex_hull.cpp
 * Description:
\\\begin{minipage}{75mm}
Returns a vector of the points of the convex hull in counter-clockwise order.
Points on the edge of the hull between two other points are not considered part of the hull.
\end{minipage}
\begin{minipage}{15mm}
\vspace{-6mm}
\includegraphics[width=\textwidth]{content/geometry/ConvexHull}
\vspace{-6mm}
\end{minipage}
 * Time: O(n \log n)
 * Status: stress-tested, tested with kattis:convexhull
*/
v<pt> convexHull(v<pt> ps) {
    if ( sz(ps) <= 1 ) return ps;
    sort(all(ps), [&](pt& a, pt& b) { return make_pair(a.x, a.y) < make_pair(b.x, b.y); } );
	v<pt> h(2*sz(ps)+1); // sz(ps) + 1 if you don't need points on the boundary
    int t = 0, s = 1;
    for (int _ = 2; _--; s = t--, reverse(all(ps))) for (pt p : ps) {
			while (t > s && orient(p, h[t-1], h[t-2]) > 0) t--;
                // >= 0 if you don't need points on the boundary
			h[t++] = p; 
		}
    return h.resize(t), h;
}
