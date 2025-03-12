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

int search(vector<int> arr, int strt, int end, int value) {
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value) break;
    }
    return i;
}

Node* buildTree(vector<int> in, vector<int> pre, int inStrt, int inEnd) {
    static int preIndex = 0;
    if (inStrt > inEnd) return nullptr;
    Node* node = new Node(pre[preIndex++]);
    if (inStrt == inEnd) return node;
    int inIndex = search(in, inStrt, inEnd, node->data);
    node->left = buildTree(in, pre, inStrt, inIndex - 1);
    node->right = buildTree(in, pre, inIndex + 1, inEnd);
    return node;
}

void printPostorder(Node* node) {
    if (node == nullptr) return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

int main() {
    vector<int> in = {4, 2, 5, 1, 3};
    vector<int> pre = {1, 2, 4, 5, 3};
    vector<int> post = {4, 5, 2, 3, 1};
    
    int len = in.size();
    Node* root = buildTree(in, pre, 0, len - 1);
    cout << "Postorder traversal of the constructed tree: \n";
    printPostorder(root);
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;
    
//     Node(int val){
//         data = val;
//         left = right = nullptr;
//     }
// };

// void levelToPreorder(int in, vector<int> v, vector<int> &n) {
//     if(in >= v.size()) return;
//     n.push_back(v[in]);
//     levelToInorder(2*in+1, v, n);
//     levelToInorder(2*in+2, v, n);
// }
// void levelToInorder(int in, vector<int> v, vector<int> &n) {
//     if(in >= v.size()) return;
//     levelToInorder(2*in+1, v, n);
//     n.push_back(v[in]);
//     levelToInorder(2*in+2, v, n);
// }
// void levelToPostorder(int in, vector<int> v, vector<int> &n) {
//     if(in >= v.size()) return;
//     levelToPostorder(2*in+1, v, n);
//     levelToPostorder(2*in+2, v, n);
//     n.push_back(v[in]);
// }


// int main() {
//     vector<int> level={1,2,3,4,5};
    
//     vector<int> pre={1,2,4,5,3};
//     vector<int> in={4,2,5,1,3};
//     vector<int> post={4,5,2,3,1};
    
//     vector<int> preFromlevel;
//     vector<int> inFromlevel;
//     vector<int> postFromlevel;
    
//     levelToPreorder(0, level, preFromlevel);
//     levelToInorder(0, level, inFromlevel);
//     levelToPostorder(0, level, postFromlevel);
    
//     if(pre==preFromlevel && in==inFromlevel && post==postFromlevel){
//         cout << "yes" << endl;
//     } else cout << "no" << endl;
    
//     return 0;
// }