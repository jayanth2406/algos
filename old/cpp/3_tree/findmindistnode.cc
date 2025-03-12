#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int v){
        data = v;
        left = right = nullptr;
    }
};

int depth(Node* rt, int k, int ht) {
    if(rt==nullptr) return -1;
    if(rt->data == k) return ht;
    int lh = depth(rt->left, k, ht+1);
    int rh = depth(rt->right, k, ht+1);
    return (lh!=-1) ? lh : rh;
}

Node* findLCA(Node* rt, int l, int r) {
    if(rt==nullptr) return nullptr;
    if(rt->data == l || rt->data == r) return rt;
    Node* llca = findLCA(rt->left, l, r);
    Node* rlca = findLCA(rt->right, l, r);
    if(llca && rlca) return rt;
    return (llca!=nullptr) ? llca : rlca;
}

int minDist(Node* rt, int l, int r) {
    Node* lca = findLCA(rt, l, r);
    int lh = depth(lca, l, 0);
    int rh = depth(lca, r, 0);
    return lh+rh;
}

int main() {
    Node* rt = new Node(1);
    rt->left = new Node(2);
    rt->right = new Node(3);
    rt->left->left = new Node(4);
    rt->left->right = new Node(5);
    rt->right->left = new Node(6);
    rt->right->right = new Node(7);
    rt->right->left->right = new Node(8);
    
    cout << "Tree is: " << minDist(rt, rt->right->data, rt->left->left->data) << "\n";
    
    return 0;
}