/**
 * Author: Chew Shao Qian
 * Date: 2025-11-12
 * License: CC0
 * Source: csq's templates
 * Description: comp[i] holds SCC index of i, note that SCC index
 * is sorted in reverse topological order 
 * Time: O(E + V)
 * Status: Stress tested on library checker
 */
#pragma once

struct SCC{
    int n,timer = 0,ccnt = 0;
    vector<int>low,tin,comp;
    stack<int>stk;
	SCC(int _n):n(_n),low(n,1e9),tin(n),comp(n){}
	void dfs(int v, vv<int>&g){
		stk.push(v);
		low[v] = tin[v] = ++timer;
		for(int x:g[v]){
			if(!tin[x])dfs(x,g);
			low[v] = min(low[v],low[x]);
		}
		if(tin[v] == low[v]){
			while(true){
				int j = stk.top();
				stk.pop();
				comp[j] = ccnt;
				low[j] = 1e9;
				if(j==v)break;
			}
            ccnt++;
		}	
	}
	void build(vv<int> g){
		for(int i=0;i<n;i++)if(!tin[i])dfs(i,g);
	}
};