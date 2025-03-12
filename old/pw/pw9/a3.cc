#include<bits/stdc++.h>
using namespace std;

struct LinkedList {
    int v;
    LinkedList* l;
    LinkedList* r;
    LinkedList(int v): v(v), l(nullptr), r(nullptr) {}
};

void readLL(LinkedList* head, unordered_map<int, int> &f) {
    if(head != nullptr) {
        readLL(head->l, f);
        f[head->v]++;
        readLL(head->r, f);
    }
}

int main() {
    LinkedList* head = new LinkedList(100);
    head->l = new LinkedList(50);
    head->r = new LinkedList(160);
    head->l->l = new LinkedList(50);
    head->l->r = new LinkedList(60);
    head->r->l = new LinkedList(140);
    head->r->r = new LinkedList(170);

    LinkedList* h2 = new LinkedList(10);
    h2->l = new LinkedList(5);
    h2->r = new LinkedList(20);
    h2->r->r = new LinkedList(170);
    h2->l->l = new LinkedList(20);

    unordered_map<int, int> freq;
    readLL(h2, freq);
    int mf=INT_MIN;
    int el=-1;
    for(auto i : freq) {
        if(i.second > mf) {
            mf = i.second;
            el = i.first;
        }
    }
    if(el != -1) {    
        cout << "Mode is " << el << " with freq: " << mf << endl;
    } else {
        cout << "Mode doesn't exist." << endl;
    }
    return 0;    
}
