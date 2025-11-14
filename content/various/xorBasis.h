/**
 * Author: 
 * Date: 
 * License: 
 * Source: stole from abc
 * Description: solve Ax=b under Z2, empty if no solution, also return the nullspace of A
 * Time: O(n \log n)
 * Status: stress-tested
*/
#pragma once
typedef bitset<(1<<12)+5> bs;
auto gauss(v<bs> a, vi b, int m) { // solve ax = b
    int n = sz(a), rk = 0;
    vi depv, free(m, 1);
    for (int i = 0; i < m && rk < n; ++i) {
        int p = rk;
        rep(j, rk, n) if ( a[j][i] ) p=j;
        if (!a[p][i] ) continue;
        swap(a[p], a[rk]), swap(b[p], b[rk]);
        rep(j, 0, n) if (j != rk && a[j][i]) {
            a[j] ^= a[rk];
            b[j] ^= b[rk];
        }
        depv.pb(i), free[i] = 0, ++rk;
    }
    v<vi> null;
    vi x;
    rep (i, 0, m) if (free[i]) {
        null.pb(vi(m)), null.back()[i] = 1;
        rep(j, 0, rk) null.back()[depv[j]] = a[j][i];
    }
    rep(i, rk, n) if (b[i]) return make_pair(x, null); // b is not in C(a)
    x.resize(m);
    rep(i, 0, rk) x[depv[i]] = b[i];
    return make_pair(x, null); // solution = x + span(null[i])
}
