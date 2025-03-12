#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// DFS - Pre, In, Post
void printTreePreOrder(Node *rt)
{
    if (rt == nullptr)
        return;
    cout << rt->data << " ";
    printTreePreOrder(rt->left);
    printTreePreOrder(rt->right);
}
void printTreeInOrder(Node *rt)
{
    if (rt == nullptr)
        return;
    printTreePreOrder(rt->left);
    cout << rt->data << " ";
    printTreePreOrder(rt->right);
}
void printTreePostOrder(Node *rt)
{
    if (rt == nullptr)
        return;
    printTreePreOrder(rt->left);
    printTreePreOrder(rt->right);
    cout << rt->data << " ";
}

// DFS using Stack - Pre, In, Post
void printTreePreOrderStack(Node *rt)
{
    if (rt == nullptr)
        return;
    stack<Node *> s;
    s.push(rt);
    Node *t = rt;
    while (!s.empty())
    {
        t = s.top();
        s.pop();
        cout << t->data << " ";
        if (t->right != nullptr)
            s.push(t->right);
        if (t->left != nullptr)
            s.push(t->left);
    }
}
void printTreeInOrderStack(Node *rt)
{
    if (rt == nullptr)
        return;
    stack<Node *> s;
    Node *t = rt;
    while (!s.empty() || t != nullptr)
    {
        while (t != nullptr)
        {
            s.push(t);
            t = t->left;
        }
        t = s.top();
        s.pop();
        cout << t->data << " ";
        t = t->right;
    }
}
void printTreePostOrder2Stack(Node *rt)
{
    if (rt == nullptr)
        return;
    stack<Node *> s1, s2;
    s1.push(rt);
    Node *t = rt;
    while (!s1.empty())
    {
        t = s1.top();
        s1.pop();
        s2.push(t);
        if (t->left != nullptr)
            s1.push(t->left);
        if (t->right != nullptr)
            s1.push(t->right);
    }
    while (!s2.empty())
    {
        cout << (s2.top())->data << " ";
        s2.pop();
    }
}
void printTreePostOrder1Stack(Node *rt)
{
    if (rt == nullptr)
        return;
    stack<Node *> s;
    Node *t = rt;
    while (t != nullptr || !s.empty())
    {
        if (t != nullptr)
        {
            s.push(t);
            t = t->left;
        }
        else
        {
            Node *t2 = s.top()->right;
            if (t2 == nullptr)
            {
                t2 = s.top();
                s.pop();
                cout << t2->data << " ";
                while (!s.empty() && t2 == s.top()->right)
                {
                    t2 = s.top();
                    s.pop();
                    cout << t2->data << " ";
                }
            }
            else
                t = t2;
        }
    }
}

// BFS
void printLevelOrdered(Node *rt)
{
    if (rt == nullptr)
        return;
    queue<Node *> q;
    q.push(rt);
    Node *t = rt;
    while (!q.empty())
    {
        t = q.front();
        cout << t->data << " ";
        if (t->left != nullptr)
            q.push(t->left);
        if (t->right != nullptr)
            q.push(t->right);
        q.pop();
    }
}

/// @brief Basic Operations
void deleteTree(Node *rt)
{
    if (rt == nullptr)
        return;
    deleteTree(rt->left);
    deleteTree(rt->right);
    delete rt;
}

Node *insertBST(Node *rt, int v)
{
    if (rt == nullptr)
        return new Node(v);
    if (v > rt->data)
        rt->right = insertBST(rt->right, v);
    if (v < rt->data)
        rt->left = insertBST(rt->left, v);
    return rt;
}

Node *createBST(int n)
{
    int v;
    cin >> v;
    Node *rt = new Node(v);
    for (int i = 1; i < n; i++)
    {
        cin >> v;
        insertBST(rt, v);
    }
    return rt;
}

int treeHeight(Node* rt) {
    if(rt==nullptr) return 0;
    return max(treeHeight(rt->left)+1, treeHeight(rt->right)+1);
}

int diameter(Node* rt) {
    if(rt==nullptr) return 0;
    int lh = treeHeight(rt->left);
    int rh = treeHeight(rt->right);
    
    int ld = diameter(rt->left);
    int rd = diameter(rt->right);
    
    return max(lh+rh+1, max(ld, rd));
}

int main()
{
    Node *rt = createBST(10);

    printTreePreOrderStack(rt);
    cout << endl;
    printTreeInOrderStack(rt);
    cout << endl;
    printTreePostOrder1Stack(rt);
    cout << endl;
    printTreePostOrder2Stack(rt);
    cout << endl;
    printLevelOrdered(rt);
    cout << endl;

    printf("Ht: %d\n", treeHeight(rt));    
    printf("Diameter: %d\n", diameter(rt));

    deleteTree(rt);
    return 0;
}