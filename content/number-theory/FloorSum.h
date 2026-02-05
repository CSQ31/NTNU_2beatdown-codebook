/**
 * Author: Atcoder Library
 * Date: 2025-02-01
 * License: CC0
 * Description: Computes sum (ax+b)//M for 0 <= i < N
 * Time: O(logM)
 * Status: Stress-tested
 */
#pragma once
typedef unsigned long long ull;
ull floor_sum(ull n,ull m,ull a,ull b) {
	ull ans = 0;
	while (true) {
		for(;a>=m;a%=m) ans += n * (n - 1) / 2 * (a / m);
		for(;b>=m;b%=m) ans += n * (b / m);
		ull y_max = a * n + b;
		if (y_max < m) break;
		n = (ull)(y_max / m);
		b = (ull)(y_max % m);
		swap(m, a);
	}
	return ans;
}
ll ufloor_sum(ll n, ll m, ll a, ll b) {
	ull ans = 0;
	if (a < 0) {
		ull a2 = (m-(abs(a)%m))%m; 
		ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);
		a = a2;
	}
	if (b < 0) {
		ull b2 = (m-(abs(b)%m))%m; 
		ans -= 1ULL * n * ((b2 - b) / m);
		b = b2;
	}
	return ans + floor_sum(n, m, a, b);
}
