// double ended queue using array in c
#include<stdio.h>
#include<stdlib.h>

int front = -1;
int rear = -1;
int size = 5;
int q[5];

void insertFront(int v) {
    if(front==-1) {
        front = rear = 0;
        q[front] = v;
    } else if(front==0) {
        printf("Queue is full\n");
    } else {
        q[--front] = v;
    }
}

void insertRear(int v) {
    if(rear==-1) {
        front = rear = 0;
        q[rear] = v;
    } else if(rear==size-1) {
        printf("Queue is full\n");
    } else {
        q[++rear] = v;
    }
}

void deleteFront() {
    if(front==-1) return;
    if(front==rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void deleteRear() {
    if(rear==-1) return;
    if(front==rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

void printQueue() {
    if(front==-1) return;
    for(int i=front; i<=rear; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main() {
    insertFront(1);
    insertFront(2);
    insertRear(3);
    insertRear(4);
    insertRear(5);
    printQueue();
    deleteFront();
    deleteRear();
    printQueue();
    return 0;
}
