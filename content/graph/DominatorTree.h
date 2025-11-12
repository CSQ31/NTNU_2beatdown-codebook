/**
 * Author: Chew Shao Qian
 * Date: 2025-11-12
 * License: CC0
 * Source: https://www.cs.princeton.edu/courses/archive/spr11/cos423/Lectures/DominatorsA.pdf#page=18 modified
 * Description: Find the immediate dominators for all nodes
 * Usage: dom_tree d(n),d.build(source,adj);
 * Time: O(E + V) 
 * Status: Stress-tested
 */
#pragma once
struct dom_tree{
    int n,timer = 0;
    v<int>tin,sdom,idom,a,p,pmin,ord;
    vv<int>g,cross,R;
    dom_tree(int _n):n(_n),tin(n),sdom(n),idom(n,-1),
                     a(n),p(n),pmin(n),g(n),cross(n),R(n){};
    inline int Min0(int a,int b){
        return tin[a] < tin[b]? a : b;}
    inline int Min1(int a,int b){
        return tin[sdom[a]] < tin[sdom[b]]? a : b;}

    int find(int x,bool mode){
        if(a[x] == -1)return x;
        if(!mode)pmin[x] = Min0(pmin[x],find(a[x],0));
        else     pmin[x] = Min1(pmin[x],find(a[x],1));
        if(a[a[x]] != -1)a[x] = a[a[x]];
        return pmin[x];
    }

    void dfs1(int v,vv<int>&adj){
        ord.push_back(v);
        tin[v] = ++timer;
        for(int x:adj[v]){
            cross[x].push_back(v);
            if(tin[x])continue;
            dfs1(x,adj);
            p[x] = v;
            g[v].push_back(x);
        }
    }
    void build(int s,vv<int>&adj){
        dfs1(s,adj);
        a.assign(n,-1);
        reverse(all(ord));
        for(int v:ord){
            sdom[v] = v;
            if(v == s)break;
            for(int u:cross[v])
                sdom[v] = Min0(sdom[v],find(u,0));
            a[v] = p[v];
            pmin[v] = sdom[v];
        }
        a.assign(n,-1);
        iota(all(pmin),0);
        for(int v:ord){
            for(int u:R[v])idom[u] = find(u,1);
            if(v == s){idom[s] = s;break;}
            for(int u:g[v])a[u] = p[u];
            R[sdom[v]].push_back(v);
        }
        reverse(all(ord));
        for(int v:ord)
            idom[v] = idom[v] == v?sdom[v]:idom[idom[v]];
    }
};