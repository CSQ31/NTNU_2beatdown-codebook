/**
 * Author: csq
 * Date: 2025-09-20
 * License: CC0
 * Source: various sources and benq
 * Description: supports inv(P),ln(P),exp(P),div(P,Q) all in nlogn.
 * Time: O(N \log N), where $N = deg(P)$ 
 * Status: stress-tested
 */
#pragma once

#include "NumberTheoreticTransform.h"
ll inv(ll a) {
  return a <= 1 ? a : mod - (mod/a) * inv(mod % a) % mod;
}
using poly = vl;
poly rsz(const poly& p, int x) { 
	if (x <= sz(p)) return poly(begin(p),begin(p)+x);
	poly q = p; q.resize(x); return q;  
}
poly& operator+=(poly& p, const poly& q) {
	p = rsz(p,max(sz(p),sz(q)));
    rep(i, 0,sz(q)) {p[i] += q[i]; if(p[i] >= mod)p[i]-=mod;}
	return p; 
}
poly& operator-=(poly& p, const poly& q) {
	p = rsz(p,max(sz(p),sz(q)));
    rep(i, 0,sz(q)) {p[i] += mod-q[i];if(p[i] >= mod)p[i]-=mod;}
	return p; 
}
poly& operator*=(poly& p, const int &k) {
    for(auto &x:p)x = (ll)x*k%mod;
    return p;
}

poly operator+(poly p, const poly& q) { return p += q; }
poly operator-(poly p, const poly& q) { return p -= q; }
poly operator-(poly p) { for(auto &x:p)x = x*(mod-1)%mod; return p; }
poly operator*(poly p, const int& k) { return p *= k; }
poly operator*(const int& k, const poly& p) { return p*k; }
poly operator*(poly p, const poly& q){return conv(p,q);}

poly dif(const poly& p) { // differentiate
	poly res;
    rep(i, 1, sz(p)) res.pb((ll)i*p[i]%mod);
	return res; 
}
poly integ(poly p){
    static poly invs{0,1};
    poly res(sz(p)+1);
    rep(i, sz(invs), sz(p)+1) invs.pb(mod - (ll)mod/i * invs[mod%i] % mod);
    rep(i, 0, sz(p)) res[i+1] = (ll)p[i]*invs[i+1] % mod;
    return res;
}
poly inv(poly A, int n) { //Q_{k+1} = Qk(2-P*Qk)
	poly B{inv(A[0])};
	for (int x = 2; x/2 < n; x<<=1) B = 2*B-rsz(conv(rsz(A,x),conv(B,B)),x);
	return rsz(B,n);
}

poly ln(poly p, int n){
    poly q = rsz(dif(p) * inv(p,n-1),n-1);
    return rsz(integ(q),n);
}

poly exp(poly A, int n) { assert(A[0] == 0);
	poly B{1}, IB{1};
	for (int x = 1; x < n; x<<=1) {
		IB = 2*IB-rsz(conv(B,conv(IB,IB)),x);
		poly Q = dif(rsz(A,x)); Q += rsz(conv(IB,dif(B)-conv(B,Q)),2*x-1); 
		B = B+rsz(conv(B,rsz(A,2*x)-integ(Q)),2*x); 
	} 
	return rsz(B,n);
}
poly div(poly a,poly b){ //rev(a)rev(b) = rev(d) mod x^(n-m+1)
    assert(b != vl({0}) && "divide by zero poly\n");
    int n = sz(a), m = sz(b);
    if(m > n)return {};
    reverse(all(a)), a = rsz(a,n-m+1);
    reverse(all(b)), b = rsz(b,n-m+1);
    poly d = rsz(a * inv(b,n-m+1),n-m+1);
    reverse(all(d));
    return d;
}
poly rem(poly a,poly b){
    int n = sz(a), m = sz(b);
    poly r = a - b*div(a,b);
    while(!r.back())r.pop_back();
    if(r.empty())r ={0};
    return r;
}