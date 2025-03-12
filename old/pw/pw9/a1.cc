#include<bits/stdc++.h>
using namespace std;

struct LinkedList {
    int v;
    LinkedList* l;
    LinkedList* r;
    LinkedList(int v): v(v), l(nullptr), r(nullptr) {}
};

bool isLeaf(LinkedList* node) {
    return (node->l == nullptr && node->r == nullptr);
}

void leftBoundary(LinkedList* head) {
    if(head != nullptr) {
        if(isLeaf(head)) return;
        cout << head->v << " ";
        if(head->l == nullptr) leftBoundary(head->r);
        leftBoundary(head->l);      
    }
}

void printLeaf(LinkedList* head) {
    if(head != nullptr) {
        printLeaf(head->l);
        if(isLeaf(head)) {
            cout << head->v << " ";
        }
        printLeaf(head->r);
    }
}

void rightBoundary(LinkedList* head) {
    if(head != nullptr) {
        if(isLeaf(head)) return;
        if(head->r == nullptr) rightBoundary(head->l);
        rightBoundary(head->r);
        cout << head->v << " ";    
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

    leftBoundary(head);
    printLeaf(head);
    rightBoundary(head->r);

    cout << endl;
    leftBoundary(h2);
    printLeaf(h2);
    rightBoundary(h2->r);
    return 0;    
}