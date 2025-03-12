#include<bits/stdc++.h>
using namespace std;

struct bt{
    int v;
    bt* l;
    bt* r;
    bt(int v) : v(v), l(nullptr), r(nullptr) {}
};

void lft(bt* t, vector<int> &v) {
    if(t!=nullptr) {
        if(!v[t->v]) {
            cout << t->v << " ";
            v[t->v]++;
        }
        if(t->l != nullptr) lft(t->l, v);
        else lft(t->r, v);
    }
}

void mft(bt* t, vector<int> &v) {
    if(t!=nullptr) {
        mft(t->l, v);
        if(t->l==nullptr && t->r==nullptr && !v[t->v]) {
            cout << t->v << " ";
            v[t->v]++;
        }
        mft(t->r, v);
    }
}

void rft(bt* t, vector<int> &v) {
    if(t!=nullptr) {
        if(t->r != nullptr) rft(t->r, v);
        else rft(t->l, v);
        if(!v[t->v]) {
            cout << t->v << " ";
            v[t->v]++;
        }
    }
}



int main() {
    vector<int> vis(14, 0);
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

    lft(t, vis);
    mft(t, vis);
    rft(t, vis);

    return 0;
}