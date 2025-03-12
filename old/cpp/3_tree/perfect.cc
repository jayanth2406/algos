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

int depth(Node* rt) {
    if(rt==nullptr) return 0;
    return (max(depth(rt->left)+1, depth(rt->right)+1));
}

int isTreePerfect(Node * rt){
    if(rt==nullptr) return 1;
    int res = isTreePerfect(rt->left) && isTreePerfect(rt->right);
    int l = depth(rt->left);
    int r = depth(rt->right);
    if(l!=r) return 0;
    return res;
}


int main() {
    Node* rt = new Node(10);
    rt->left = new Node(20);
    rt->right = new Node(30);
    rt->left->left = new Node(40);
    rt->left->right = new Node(50);
    rt->right->left = new Node(60);
    rt->right->right = new Node(70);
    
    
    cout << "Tree is: " << 
    (isTreePerfect(rt)==1 ? "perfect." : "Not perfect.") 
    << "\n";
    
    return 0;
}