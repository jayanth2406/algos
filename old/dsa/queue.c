#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(queue->rear==NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

void dequeue(struct Queue* queue) {
    if(queue->front==NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
}

void printAllNode(struct Queue* queue) {
    struct Node* temp = queue->front;
    while(temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    struct Queue* queue = createQueue();
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    printAllNode(queue);
    dequeue(queue);
    printAllNode(queue);
    dequeue(queue);
    printAllNode(queue);
    dequeue(queue);
    printAllNode(queue);
    return 0;
}