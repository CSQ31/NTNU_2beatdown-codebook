/**
 * Author: CSQ
 * Date: 2025-02-23
 * License: CC0
 * Source: self
 * Description: Sparse segment tree without pointers
 * Time: O(\log N)
 * Status: stress-tested
 */

#pragma once
const int M = 1e7;
int ch[2][M],sum[M];
int ndcnt = 0;
int create(){return ++ndcnt;}
int copy(int v){
    int u = create();
    ch[0][u] = ch[0][v];
    ch[1][u] = ch[1][v];
    sum[u] = sum[v];
    return u;
}
int upd(int v,int l,int r,int pos,int val){
    int u = copy(v);
    if(l==r){
        sum[u] += val;
        return u;
    }
    int tm = (l+r)/2;
    if(pos <= tm)ch[0][u] = upd(ch[0][u],l,tm,pos,val);
    else         ch[1][u] = upd(ch[1][u],tm+1,r,pos,val);
    sum[u] = sum[ch[0][u]] + sum[ch[1][u]];
    return u;
}
int query(int v,int l,int r,int tl,int tr){
    if(!v || l > r)return 0;
    if(l == tl && r == tr)return sum[v];
    int tm = (tl+tr)/2;
    return query(ch[0][v],l,min(r,tm),tl,tm) + 
           query(ch[1][v],max(l,tm+1),r,tm+1,tr);
}