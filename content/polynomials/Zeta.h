/**
 * Author: DF
 * Date: 2025-11-12
 * License: 
 * Source: https://codeforces.com/blog/entry/119082
 * Description: 1-index zeta transform for gcd convolution and lcm convolution.
 * There should be another function(Mobius) that reverse the change after multiply every entry
 * Usage:
	zeta(a), zeta(b);
	rep(i,0,n) c[i]=a[i]*b[i];
	reverseZeta(c);
 * Status: stress-tested
 */
#pragma once
#include "../number-theory/Sieve.h"

void zeta(vi& v) {
	int n = sz(v)-1;
	for (int p : ps) {
		for (int i = 1; i*p <= n; ++i) v[i * p] += v[i]; // divisor zeta, for lcm
		for (int i = n/p; i; --i) v[i] += v[i * p]; // multiple zeta, for gcd
	}
}
