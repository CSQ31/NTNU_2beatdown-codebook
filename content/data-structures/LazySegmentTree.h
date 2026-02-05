/**
 * Author: Chew Shao Qian
 * Date: 2025-02-05
 * License: CC0
 * Source: csq
 * Description: lazy segment tree skeleton, merge, apply and push depends on problem at hand
 * Time: O(\log N).
 * Usage: Node* tr = new Node(v, 0, sz(v));
 * Status: stress-tested a bit
 */
#pragma once
struct node{
    //ll sum = 0,mul = 1,add = 0;
    node(){}
}t[444444];
node merge(node a,node b){}
void apply(node &v,int l,int r){}
void push(int v,int l,int r){}
void upd(int v,int l,int r,int tl,int tr){
    if(l>r)return;
    if(l == tl && r == tr){
        //apply(t[v],change,l,r);
        return;
    }
    int tm = (tl+tr)/2;
    push(v,tl,tr);
    upd(2*v,l,min(r,tm),tl,tm);
    upd(2*v+1,max(l,tm+1),r,tm+1,tr);
    t[v] = merge(t[2*v],t[2*v+1]);
}
node query(int v,int l,int r,int tl,int tr){
    if(l>r)return node();
    if(l == tl && r == tr)return t[v];
    int tm = (tl+tr)/2;
    push(v,tl,tr);
    return merge(query(2*v,l,min(r,tm),tl,tm), 
                 query(2*v+1,max(l,tm+1),r,tm+1,tr));
}
void build(int v,int l,int r,vector<ll> &a){
    if(l == r){
        t[v].sum = a[l];
        return;
    }
    int tm = (l+r)/2;
    build(2*v,l,tm,a);
    build(2*v+1,tm+1,r,a);
    t[v] = merge(t[2*v],t[2*v+1]);
}