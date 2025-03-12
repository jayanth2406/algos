#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

void treeToVecInorder(Node* rt, vector<int> &n){
    if(rt==nullptr) return;
    treeToVecInorder(rt->left, n);
    n.push_back(rt->data);
    treeToVecInorder(rt->right, n);
}

void findNInorder(Node* rt, int n) {
    vector<int> v;
    treeToVecInorder(rt, v);
    printf("%d node is: %d", n, v[n-1]);
}

int main() {
    Node* rt = new Node(10);
    rt->left = new Node(20);
    rt->right = new Node(30);
    rt->left->left = new Node(40);
    rt->left->right = new Node(50);
    
    findNInorder(rt, 4);
    
    return 0;
}