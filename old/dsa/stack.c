#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(struct Stack* stack) {
    if(stack->top==NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}

void printAllNode(struct Stack* stack) {
    struct Node* temp = stack->top;
    while(temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Stack* stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printAllNode(stack);
    pop(stack);
    printAllNode(stack);
    pop(stack);
    printAllNode(stack);
    pop(stack);
    printAllNode(stack);
    pop(stack);
    return 0;
}