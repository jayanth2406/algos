#include<bits/stdc++.h>
using namespace std;

struct ll{
    int v;
    ll* n;
    ll(int v, ll* n) : v(v), n(n) {}
    ll(int v) : v(v), n(nullptr) {}
};

ll* sum(ll* a, ll* b) {
    ll* rs;
    int ak=0, bk=0, r=0;
    while(a!=nullptr) {
        ak = (ak*10) + a->v;
        a=a->n;
    }
    while(b!=nullptr) {
        bk = (bk*10) + b->v;
        b=b->n;
    }
    r=ak+bk;
    list<int> kn;
    while (r>0)
    {
        kn.push_back(r%10);
        r/=10;
    }
    rs = new ll(kn.back());
    kn.pop_back();
    ll* ks = rs;
    while(kn.size() > 0) {
        ks->n = new ll(kn.back());
        kn.pop_back();
        ks=ks->n;
    }
    return rs;
}

void prt(ll* h) {
    while(h!=nullptr) {
        cout << h->v << " ";
        h=h->n;
    }
}

int main() {
    ll* a = new ll(0);
    a->n = new ll(0);
    a->n->n = new ll(6);
    a->n->n->n = new ll(3);
    prt(a);
    cout << endl;

    ll* b = new ll(0);
    b->n = new ll(7);
    prt(b);
    cout << endl;

    ll* r = sum(a, b);
    prt(r);
    return 0;
}