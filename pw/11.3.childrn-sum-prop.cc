#include<bits/stdc++.h>
using namespace std;

struct bt{
    int v;
    bt* l;
    bt* r;
    bt(int v): v(v), l(nullptr), r(nullptr) {}
};

bool checkcsp(bt* t) {
    if(t == nullptr || (t->l == nullptr && t->r == nullptr)){
        return true;
    }
    int lv = (t->l == nullptr) ? 0 : t->l->v;
    int rv = (t->r == nullptr) ? 0 : t->r->v;
    if(t->v == lv+rv) {
        return checkcsp(t->l) && checkcsp(t->r);
    } else {
        return false;
    }
}

int main() {
    bt* t = new bt(10);
    t->l = new bt(8);
    t->r = new bt(2);
    t->l->l = new bt(3);
    t->l->r = new bt(5);
    t->r->l = new bt(2);

    bool bl = checkcsp(t);
    cout << bl;
    return 0;
}