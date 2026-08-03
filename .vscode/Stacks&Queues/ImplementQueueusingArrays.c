#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Queue{
    int* arr;
    int front;
    int rear;
    int capacity;
}Queue;

Queue* createQueue(int n){
    Queue* myQueue = (Queue*)malloc(sizeof(Queue));
    myQueue->front = 0;
    myQueue->rear = -1;
    myQueue->capacity = n;
    myQueue->arr = (int*)malloc(n*sizeof(int));
    return myQueue;
}

bool isEmpty(Queue* q){
    return(q->rear<q->front);
}

bool isFull(Queue* q){
    if(q->rear == (q->capacity)-1) return true;
    return false;
}

void enqueue(Queue* q, int x){
    if(isFull(q)) return;
    else{
        q->rear++;
        q->arr[q->rear] = x;
    }
}

void dequeue(Queue* q){
    if(isEmpty(q)) return;
    else{
        q->front++;
    }
}

int getRear(Queue* q){
    if(isEmpty(q)) return -1;
    else{
        return q->arr[q->rear];
    }
}

int getFront(Queue* q){
    if(isEmpty(q)) return 0;
    else{
        return q->arr[q->front];
    } 
}