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

int checkMirror(Node* rt1, Node* rt2) {
    vector<int> v1, v2;
    treeToVecInorder(rt1, v1);
    treeToVecInorder(rt2, v2);
    for(int i=0; i<v1.size(); i++) {
        if(v1[i] != v2[v2.size()-i-1]) return 0;
    }
    return 1;
}

int main() {
    Node* rt = new Node(1);
    rt->left = new Node(3);
    rt->right = new Node(2);
    rt->right->left = new Node(5);
    rt->right->right = new Node(4);
    
    Node* rt2 = new Node(1);
    rt2->left = new Node(2);
    rt2->right = new Node(3);
    rt2->left->left = new Node(4);
    rt2->left->right = new Node(5);
    
    int b = checkMirror(rt, rt2);
    if(b==1) printf("Mirror");
    else printf("No Mirror");
    
    return 0;
}