#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

void addNode(int v, struct node ** head){
    struct node * newNode, * temp=*head;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = v;
    newNode->next = NULL;
    if(temp==NULL) *head = newNode;
    else{
        while(temp->next != NULL) temp=temp->next;
        temp->next = newNode;
    }
}

void deleteNodeAtPos(int pos, struct node * head){
    struct node * temp=head;
    if(pos==1) {
        temp = head;
        head = head->next;
        free(temp);
    } else {
        struct node * delNode;
        int x=2;
        while(temp->next!=NULL) {
            if(x==pos) {
                delNode = temp->next;
                temp->next = temp->next->next;
                free(delNode);
            }
            x++;
            temp=temp->next;
        }
    }
}

void deleteAllNodesAtOddPos(struct node ** head, int size){
    struct node * newHead=NULL, *temp=*head;
    for(int i=1; i<=size && temp!=NULL; i++) {
        if(i%2==0) addNode(temp->data, &newHead);
        temp=temp->next;
    }
    *head = newHead;
}

void deleteAllNodesOfCertainValue(struct node ** head, int size, int val) {
    struct node * newHead=NULL, *temp=*head;
    while(temp!=NULL) {
        if(val != temp->data) addNode(temp->data, &newHead);
        temp=temp->next;
    }
    *head = newHead;
}

void printAllNodes(struct node * head) {
    struct node * temp=head;
    while(temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printOddEven(struct node * head) {
    struct node * temp=head;
    int oddCt=0, evenCt=0;
    while(temp!=NULL) {
        if((temp->data)%2==0) evenCt++;
        else oddCt++;
        temp = temp->next;
    }
    printf("Even Count: %d, Odd Count: %d\n", evenCt, oddCt);
}

void reversePrintAllNodes(struct node * head) {
    if(head==NULL) return;
    reversePrintAllNodes(head->next);
    printf("%d ", head->data);
}

void printNthNodefromEnd(struct node * head, int nth, int size) {
    struct node * temp = head;
    size=size-nth;
    while(temp->next!=NULL && size!=0) {
        size--;
        temp=temp->next;
    }
    printf("%dth node from last: %d", nth, temp->data);
}

void printMiddleElement(struct node * head, int size){
    struct node * temp = head;
    size = size/2;
    while(temp->next!=NULL && size!=0) {
        size--;
        temp=temp->next;
    }
    printf("Middle Element is: %d", temp->data);
}

int main() {
    int n, val;
    struct node * head = NULL;
    printf("Enter total size of nodes to input: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        printf("Enter %dth element: ", i+1);
        scanf("%d", &val);
        addNode(val, &head);
    }
    printAllNodes(head);
    printOddEven(head);
    //// 
    printf("Printing in reverse order: ");
    struct node * temp=head;
    reversePrintAllNodes(temp);
    printf("\n");
    ////
    printf("Enter nth value to print from last: ");
    scanf("%d", &val);
    printNthNodefromEnd(head, val, n);
    printf("\n");
    ////
    printMiddleElement(head, n);
    printf("\n");
    ///
    // deleteAllNodesAtOddPos(&head, n);
    printf("Enter value to remove from node: ");
    scanf("%d", &val);
    deleteAllNodesOfCertainValue(&head, n, val);
    printAllNodes(head);
    return 0;
}