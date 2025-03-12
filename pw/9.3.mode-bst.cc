#include<bits/stdc++.h>
using namespace std;

struct bt{
    int v;
    bt* l;
    bt* r;
    bt(int v) : v(v), l(nullptr), r(nullptr) {}
};

void trv(bt* t, unordered_map<int, int> &f) {
    if(t==nullptr) return;
    f[t->v]++;
    trv(t->l, f);
    trv(t->r, f);
}

int main() {
    bt* t = new bt(100); 
    t->l = new bt(50);
    t->l->l = new bt(50);
    t->l->r = new bt(60);
    t->r = new bt(160);
    t->r->r = new bt(6);
    t->r->r->r = new bt(170);
    t->r->r->r->l = new bt(140);

    unordered_map<int, int> f;
    trv(t, f);

    int mx=0, mf=INT_MIN;
    for(auto x : f) {
        if(x.second > mf) {
            mx = x.first;
            mf = x.second;
        }
    }
    cout << "Mode of BST: " << mx << " of freq: " << mf << endl;
    return 0;
}