/**
 * Author: Chew Shao Qian
 * Date: 2025-11-12
 * License: CC0
 * Source: OIwiki/csq templates
 * Description: Returns the block cut tree in tree
 * Block nodes labels >= n
 * A node is an articulation point if it is connected 
 * to exactly one block node
 * Status: stress tested
 */
struct BCC{
    int n,n0,timer = 0;
    stack<int>stk;
    v<int>tin,low;
    vv<int>tree;
    void dfs(int v,int p,vv<pii>&g){
        tin[v] = low[v] = ++timer;
        stk.push(v);
        for(auto [x,id]: g[v]){
            if(id == p)continue;
            if(tin[x])low[v] = min(low[v],tin[x]);
            else{
                dfs(x,id,g);
                low[v] = min(low[v],low[x]);	
                if(low[x] >= tin[v]){
                    tree[v].pb(n0);
                    tree[n0].pb(v);
                    while(tree[n0].back() != x ){
                        tree[n0].pb(stk.top());
                        tree[stk.top()].pb(n0);
                        stk.pop();
                    }
                    n0++;
                }
            }
        }
    }
    BCC(int _n):n(_n),n0(_n),tin(_n),low(_n),tree(2*_n){}
    void build(vv<pii>&g){
        for(int i=0;i<n;i++)if(!tin[i])dfs(i,-1,g);
    }
};