/**
 * Author: Chew Shao Qian
 * Date: 2025-11-12
 * License: CC0
 * Source: folklore
 * Description: All 2CC are returned in ans
 * Status: stress tested
 */
#pragma once
const int N = 2e5;
vector<int>adj[N];
int tin[N],low[N],timer = 0;
vector<vector<int>>ans;
stack<int>stk;
void dfs(int v,int u){
	bool p = 0;
	tin[v] = low[v] = ++timer;
	stk.push(v);
	for(int x:adj[v]){
		if(x != u || p){
			if(!tin[x]){
				dfs(x,v);
			    low[v] = min(low[v],low[x]);
			}else low[v] = min(low[v],tin[x]);
		}
		else p = 1;
	}
	if(low[v] == tin[v]){
		vector<int>c;
		while(stk.top() != v){
			c.pb(stk.top());
			stk.pop();
		}
		c.pb(v);
		stk.pop();
		ans.pb(c);
	}
}
