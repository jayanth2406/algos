#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * pre, *next;
};

void addNode(struct node ** xhead, int v) {
    struct node * temp = *xhead, *newNode = NULL;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = v;
    if(temp==NULL) *xhead = newNode;
    else {
        while(temp->next!=head) temp=temp->next;
        temp->next = newNode;
        newNode->next = *xhead;
        newNode->pre = temp;
    }
}

void addOddEvenNode(struct node * head, struct node ** evenHead, struct node ** oddHead){
    struct node * t=head;
    while(t!=head){
        if((t->data)%2==0) addNode(evenHead, t->data);
        else addNode(oddHead, t->data);
        t = t->next;
    }
}

void printAllNodes(struct node ** xhead){
    struct node * temp=*xhead;
    while(temp!=*xhead) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, v;
    struct node * head;
    struct node * evenHead;
    struct node * oddHead;
    for(int i=0; i<5; i++){
        addNode(&head, i);
    }
    printAllNodes(&head);
    addOddEvenNode(head, &evenHead, &oddHead);
    printAllNodes(&evenHead);
    printAllNodes(&oddHead);
    return 0;
}