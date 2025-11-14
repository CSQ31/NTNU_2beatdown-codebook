/**
 * Author: Chew Shao Qian
 * Date: 2025-11-14
 * License: CC0
 * Source: own work
 * Description: Line range insetion and point queries, range insertion use upd2 in double log, 
 * upd1 is global insertion in single log, Note min conv use chains (i+j,Ai+Bj) instead of lines
 * Time: O(\log N)
 * Status: stress-tested
 */
#pragma once

int Div(int a){ return (a/2) - ((a < 0) && (a & 1));}
const ll INF = LLONG_MAX;
struct line{
    ll m = 0,c = INF;
    line(){};
    line(ll _m,ll _c): c(_c),m(_m){}
    ll eval(ll x){return m*x + c;}
};
struct node{
    line L0;
    node *lf = NULL,*rg = NULL;
    node(){}
    //for max just flip all <,>
    void upd1(int l,int r,line L1){
        if(l == r){
            if(L1.eval(l) < L0.eval(l))L0 = L1;
            return;
        }
        int tm = Div(l+r);
        if(L0.m < L1.m)swap(L0,L1);
        if(L1.eval(tm) < L0.eval(tm)){
            if(!lf)lf = new node();
            lf->upd1(l,tm,L0);
            L0 = L1;
        }else {
            if(!rg)rg = new node();
            rg->upd1(tm+1,r,L1);
        }
    }
    void upd2(int l,int r,int tl,int tr,line L1){
        if(l>r)return;
        if(l == tl && r == tr){
            upd1(l,r,L1);
            return;
        }
        if(!lf)lf = new node();
        if(!rg)rg = new node();
        int tm = Div(tl+tr);
        if(L0.m || L0.c != INF){
            lf->upd1(tl,tm,L0);
            rg->upd1(tm+1,tr,L0);
            L0 = line();
        }
        lf->upd2(l,min(r,tm),tl,tm,L1);
        rg->upd2(max(l,tm+1),r,tm+1,tr,L1);
    }
    ll query(int l,int r,int x,ll mn = INF){
        mn = min(mn,L0.eval(x));
        if(l == r){return mn;}
        int tm = Div(l+r);
        if(x <= tm){
            if(!lf)return mn;
            return lf->query(l,tm,x,mn);
        }else{
            if(!rg)return mn;
            return rg->query(tm+1,r,x,mn);
        }
    }
};