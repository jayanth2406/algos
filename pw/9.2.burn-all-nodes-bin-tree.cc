#include<bits/stdc++.h>
using namespace std;

struct bt{
    int v;
    bt* l;
    bt* r;
    bt(int v) : v(v), l(nullptr), r(nullptr) {}
};

void togrp(bt* t, vector<vector<int>> &adj) {
    if(t == nullptr) return;
    if(t->l != nullptr) {
        adj[t->v].push_back(t->l->v);
        adj[t->l->v].push_back(t->v);
    }
    if(t->r != nullptr) {
        adj[t->v].push_back(t->r->v);
        adj[t->r->v].push_back(t->v);
    }
    togrp(t->l, adj);
    togrp(t->r, adj);
}

void dfs(int s, vector<int> &pt, vector<vector<int>> &adj, vector<int> &v) {
    v[s]++;
    for(auto x : adj[s]) {
        if(!v[x]) {            
            pt[x] = pt[s]+1;
            dfs(x, pt, adj, v);
        }
    }
}

int main() {
    bt* t = new bt(1); 
    t->l = new bt(2);
    t->l->l = new bt(4);
    t->l->l->l = new bt(7);
    t->l->l->l->r = new bt(11);
    t->l->l->l->r->r = new bt(13);
    t->l->r = new bt(5);
    t->l->r->l = new bt(8);
    t->l->r->r = new bt(9);
    t->r = new bt(3);
    t->r->r = new bt(6);
    t->r->r->r = new bt(10);
    t->r->r->r->l = new bt(12);

    vector<vector<int>> adj(14);
    vector<int> v(14, 0);
    vector<int> pt(14, 0);
    int tgt=8;

    togrp(t, adj);
    dfs(tgt, pt, adj, v);
    int pth = *max_element(pt.begin(), pt.end());
    cout << pth << endl;
    for(int i=0; i<pt.size(); i++) {
        cout << i << ":" << pt[i] << " ";
    }
    return 0;
}