/**
 * Author: Chew Shao Qian
 * Date: 2017-05-11
 * License: CC0
 * Source: folklore
 * Description: Computes sum of a[1..i][l..r],
 * All points must be known beforehand, call add on all then init()
 * Status: stress-tested
 */
#pragma once

#include "FenwickTree.h"

struct fenwick2{
    int n;
    vector<fenwick>f;
    vv<int>pts;
    fenwick2(int _n):n(_n),f(n+1),pts(n+1){}
    void add(int x,int y){
        for(;x<=n;x += x&(-x))pts[x].push_back(y);
    }
    void init(){
        for(int i=1;i<=n;i++){
            sort(all(pts[i]));
            pts[i].resize(unique(all(pts[i])) - pts[i].begin());
            f[i] = fenwick(sz(pts[i]));
        }
    }
    void upd(int x,int y,int w){ //(x,y) must be added
        for(;x<=n;x += x&(-x))
            f[x].upd(lower_bound(all(pts[x]),y) - pts[x].begin()+1,w);
    }
    ll query(int x,int l,int r){
        ll ans = 0;
        for(;x>0;x -= x&(-x)){
            ans += f[x].query(lower_bound(all(pts[x]),l) - pts[x].begin());
            ans -= f[x].query(upper_bound(all(pts[x]),r) - pts[x].begin());
        }
        return ans;
    }
};
