// queue using stack in c
#include<stdio.h>
#include<stdlib.h>

int top1 = -1;
int top2 = -1;
int size = 5;
int s1[5];
int s2[5];

void push1(int v) {
    if(top1==size-1) {
        printf("Queue is full\n");
    } else {
        s1[++top1] = v;
    }
}

void push2(int v) {
    if(top2==size-1) {
        printf("Queue is full\n");
    } else {
        s2[++top2] = v;
    }
}

int pop1() {
    if(top1==-1) return -1;
    return s1[top1--];
}

int pop2() {
    if(top2==-1) return -1;
    return s2[top2--];
}

void enqueue(int v) {
    push1(v);
}

void dequeue() {
    if(top2==-1) {
        while(top1!=-1) {
            push2(pop1());
        }
    }
    pop2();
}

void printQueue() {
    if(top2==-1) {
        while(top1!=-1) {
            push2(pop1());
        }
    }
    for(int i=top2; i>=0; i--) {
        printf("%d ", s2[i]);
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printQueue();
    dequeue();
    printQueue();
    enqueue(4);
    printQueue();
    dequeue();
    printQueue();
    return 0;
}


