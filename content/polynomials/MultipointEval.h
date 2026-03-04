/**
 * Author: CSQ
 * Date: 2025-02-21
 * License: CC0
 * Source: self
 * Description: evaluates P(x1),P(x2),...,P(xn) in nlogn, coefficients of P are stored in f
 * Usage: mulitpoint(f,x), P(x) = f0 + f1x + f2x^2...
 * Time: O(n\log^2n)
 * Status: stress-tested
 */
#pragma once
#include "NumberTheoreticTransform.h"
vl multipoint(vl f,vl x){
    int m = sz(x);
    vl up[2*m],dn[2*m];
    for(int i=0;i<m;i++)up[i+m-1] = {mod-x[i],1};
    for(int i=m-2;i>=0;i--){
        up[i] = conv(up[2*i+1],up[2*i+2]);
        while(!up[i].back())up[i].pop_back();
    }

    dn[0] = f;
    for(int i=0;i<2*m;i++)dn[i] = rem(dn[(i-1)/2],up[i]);
    
    vl res(m);
    for(int i=0;i<m;i++)res[i] = dn[i+m-1][0];
    return res;
}