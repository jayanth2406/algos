#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int v) {
        data = v;
        prev = next = nullptr;
    }
};

struct Queue {
    Node* front;
    Node* rear;

    Queue() {
        front = rear = nullptr;
    }
};

void enqueueFront(Queue* q, int v) {
    if(q->front == nullptr) q->front = q->rear = new Node(v);
    else {
        Node * n = new Node(v);
        n->next = q->front;
        q->front->prev = n;
        q->front = n;
    }
}

void enqueueRear(Queue* q, int v) {
    if(q->rear == nullptr) q->rear = q->front = new Node(v);
    else {
        Node* n = new Node(v);
        n->prev = q->rear;
        q->rear->next = n;
        q->rear = n;
    }
}

void dequeueFront(Queue* q) {
    if(q->front == nullptr) return;
    else {
        Node* t = q->front;
        q->front = t->next;
        delete(t);
    }
}

void dequeueRear(Queue* q) {
    if(q->rear == nullptr) return;
    else {
        Node* t = q->rear;
        q->rear = t->prev;
        delete(t);
    }
}

void printAllQueue(Queue* q) {
    Node*t = q->front;
    while (t!= nullptr) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;   
}

int main() {
    Queue* q = new Queue();
    enqueueFront(q, 1);
    printAllQueue(q);
    enqueueFront(q, 2);
    printAllQueue(q);
    enqueueRear(q, 3);
    printAllQueue(q);
    enqueueFront(q, 4);
    printAllQueue(q);
    enqueueRear(q, 5);
    printAllQueue(q);
    dequeueFront(q);
    printAllQueue(q);
}