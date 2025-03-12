#include<stdio.h>
#include<stdlib.h>

struct node {
    int d;
    struct node* l;
    struct node* r;
};

int inorder[10], i=0;

void swap(int*a, int*b) {
    int t = *a;
    *a = *b;
    *b = t;
}

struct node* createNode(int v) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->d = v;
    n->l = n->r = NULL;
    return n;
}

void treeToInorder(struct node* rt) {
    if(rt==NULL) return;
    treeToInorder(rt->l);
    inorder[i++] = rt->d;
    treeToInorder(rt->r);
}

int minSwap() {
    int sp=0;
    for (int i = 0; i < 10; i++)
    {
        int min=i;
        for (int j = i+1; j < 10; j++)
        {
            if(inorder[min] > inorder[j]) min = j;
        }
        if(min!=i) {
            swap(&inorder[min], &inorder[i]);
            sp++;
        }
    }
    return sp;
}

int main() {
    struct node* rt = createNode(5);
    rt->l = createNode(6);
    rt->r = createNode(7);
    rt->l->l = createNode(8);
    rt->l->r = createNode(9);
    rt->r->l = createNode(10);
    rt->r->r = createNode(11);

    treeToInorder(rt);
    printf("Min swap: %d", minSwap());
    
}