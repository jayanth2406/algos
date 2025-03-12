#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* l;
    Node* r;
    Node(int v): val(v), l(nullptr), r(nullptr) {}
};

bool isChildrenSum(Node* node) {
    if (node == nullptr || (node->l == nullptr && node->r == nullptr)) {
        return true;
    }

    int lv = (node->l != nullptr) ? node->l->val : 0;
    int rv = (node->r != nullptr) ? node->r->val : 0;

    if (node->val == lv + rv) {
        return isChildrenSum(node->l) && isChildrenSum(node->r);
    }
    return false;
}

int main() {
    Node* root = new Node(10);
    root->l = new Node(8);
    root->r = new Node(2);
    root->l->l = new Node(3);
    root->l->r = new Node(5);
    root->r->l = new Node(2);
    root->r->r = new Node(0);

    if (isChildrenSum(root)) {
        cout << "The binary tree satisfies the children sum property." << endl;
    } else {
        cout << "The binary tree does not satisfy the children sum property." << endl;
    }

    return 0;
}