/**
 * Author: Chew Shao Qian
 * Date: 2025-09-08
 * License: CC0
 * Source: folklore
 * Description: One-indexed fenwick tree
 * Time: Both operations are $O(\log N)$.
 * Status: Stress-tested
 */
#pragma once

struct fenwick{
	int n;
	vector<ll>bit;
	void upd(int pos,ll val){
		for(int i=pos;i<=n;i+=i&(-i))bit[i]+=val;
	}
	ll query(int r){
		ll res = 0;
		for(int i=r;i>0;i-=i&(-i))res+=bit[i];
	    return res;
	}
	int search(ll val){
		ll sum = 0,pos = 0;
		for(int i=19;i>=0;i--){
			if(pos+(1<<i) < n && sum+bit[pos+(1<<i)]<val){
				pos+=(1<<i);
				sum+=bit[pos];
			}
		}
		return pos+1;
	}
	fenwick(int _n):n(_n),bit(vector<ll>(n+1,0)){}
};
