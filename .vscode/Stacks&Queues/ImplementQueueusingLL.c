#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
    int data;
    Node* next;
}Node;

typedef struct myQueue{
    Node* front;
    Node* rear;
    int currSize;
}myQueue;

Node* createNode(int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void initQueue(myQueue* q){
    q->front = NULL;
    q->rear = NULL;
    q->currSize = 0;
}

bool isEmpty(myQueue* q){
    if(q->currSize==0) return true;
    return false;
}

void enqueue(myQueue* q, int x){
    Node* newNode = createNode(x);
    if(isEmpty(q)){
        q->front = newNode;
        q->rear = newNode;
    }
    else{
    q->rear->next = newNode;
    q->rear = q->rear->next;
    }
    q->currSize++;
}

void dequeue(myQueue* q){
    if(isEmpty(q)) return;
    else if(q->currSize==1){
        Node* temp = q->front;
        q->front = NULL;
        q->rear = NULL;
        free(temp);
        q->currSize--;
    }
    else{
    Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->currSize--;
    }
}

int getFront(myQueue* q){
    if(isEmpty(q)) return -1;
    return q->front->data;
}

int size(myQueue* q){
    return q->currSize;
}