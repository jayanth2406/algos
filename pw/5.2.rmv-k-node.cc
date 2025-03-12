#include<bits/stdc++.h>
using namespace std;

struct ll{
    int v;
    ll* n;
    ll(int v) : v(v), n(nullptr) {}
    ll(int v, ll* n) : v(v), n(n) {}
};

void prt(ll* h) {
    if(h!=nullptr) {
        cout << h->v << " ";
        prt(h->n);
    }
}

int main() {
    ll* h = new ll(1);
    h->n = new ll(2);
    h->n->n = new ll(3);
    h->n->n->n = new ll(4);
    h->n->n->n->n = new ll(5);

    int k=2;

    prt(h);
    cout << endl;

    ll* t=h;
    while(k--) {
        t=t->n;
    }
    ll* l=t->n;
    t->n = t->n->n;
    delete l;
    prt(h);
    return 0;
}