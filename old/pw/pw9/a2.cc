#include<bits/stdc++.h>
using namespace std;

struct LinkedList {
    int v;
    LinkedList* l;
    LinkedList* r;
    LinkedList(int v): v(v), l(nullptr), r(nullptr) {}
};

int llsize(LinkedList* node, int k) {
    if(node->l == nullptr && node->r == nullptr) {
        return -1;
    } else {
        int le=0, ri=0;
        if(k == node->v) return -1;
        if(node->l != nullptr) le = 1 + llsize(node->l, k);
        if(node->r != nullptr) ri = 1 + llsize(node->r, k);
        return max(le, ri);
    }
}


int main() {
    LinkedList* head = new LinkedList(1);
    head->l = new LinkedList(2);
    head->r = new LinkedList(3);
    head->l->l = new LinkedList(4);
    head->l->r = new LinkedList(5);
    head->l->l->l = new LinkedList(7);
    head->l->l->l->r = new LinkedList(11);
    head->l->l->l->r->r = new LinkedList(13);
    head->l->r->l = new LinkedList(8);
    head->l->r->r = new LinkedList(9);
    head->r->r = new LinkedList(6);
    head->r->r->r = new LinkedList(10);
    head->r->r->r->l = new LinkedList(12);

    LinkedList* h2 = new LinkedList(20);
    h2->l = new LinkedList(8);
    h2->r = new LinkedList(22);
    h2->r->r = new LinkedList(25);
    h2->l->l = new LinkedList(4);
    h2->l->r = new LinkedList(12);
    h2->l->r->l = new LinkedList(10);
    h2->l->r->r = new LinkedList(14);

    int k=7;

    int size = llsize(head, -1);
    int ks = llsize(head, k);
    cout << size+ks << " ";
    return 0;    
}
