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

void treeToVec(Node* rt, vector<int> &n){
    if(rt==nullptr) return;
    n.push_back(rt->data);
    treeToVec(rt->left, n);
    treeToVec(rt->right, n);
}

int checkDuplicate(Node* rt) {
    vector<int> v;
    treeToVec(rt, v);
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++){
            if(v[i]==v[j]) {
                printf("Duplicate val: %d\n", i);
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    Node* rt = new Node(1);
    rt->left = new Node(20);
    rt->right = new Node(3);
    rt->right->right = new Node(4);
    
    int b = checkDuplicate(rt);
    if(b==1) printf("Duplicate");
    else printf("No Duplicate");
    return 0;
}