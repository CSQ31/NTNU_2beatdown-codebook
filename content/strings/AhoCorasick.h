/**
 * Author: Chew Shao Qian
 * Date: 2023-09-17
 * License: CC0
 * Source: csq's code
 * Description: AC automaton, run add on all strings then run build to intialize.
 * Replace ch with a map if alphabet size is too big
 * Time: construction takes $O(26N)$
 * Status: stress-tested
 */
#pragma once

const int MAXN = 1e6,alp = 26;
int ndcnt = 0;
int fail[MAXN],dep[MAXN]; 
int ch[alp][MAXN],go[alp][MAXN];

vector<int>id[MAXN],udep[MAXN];//strings node v contains
void add(string s,int x){
	int n = sz(s);
	int cur = 0;
	for(int i=0;i<n;i++){
		int c = s[i] - 'a'; //= lab[s[i]];
		if(!ch[c][cur])ch[c][cur] = ++ndcnt;
		cur = ch[c][cur];
	}
	id[cur].push_back(x);
}
void build(){
	queue<int>q;
	for(int i=0;i<alp;i++){
		go[i][0] = ch[i][0];
		if(ch[i][0]){
           dep[ch[i][0]] = 1;
            q.push(ch[i][0]);
        }
	}
	udep[0].push_back(0);

	while(!q.empty()){
		int u = q.front();
		udep[dep[u]].push_back(u);
		q.pop();
		for(int i=0;i<alp;i++){
			int v = ch[i][u];
			if(v){
				go[i][u] = v;
				fail[v] = go[i][fail[u]]; 

				dep[v] = dep[u]+1;
				q.push(v);
			}else{
				go[i][u] = go[i][fail[u]];
			}
		}
	}
}