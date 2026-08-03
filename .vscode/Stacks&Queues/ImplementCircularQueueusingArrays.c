#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct CircularQueue{
    int* arr;
    int capacity;
    int front;
    int rear;
}CircularQueue;

CircularQueue* createQueue(int n){
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->capacity = n;
    q->front = -1;
    q->rear = -1;
    q->arr = (int*)malloc(n*sizeof(int));
    return q; 
}

bool isFull(CircularQueue* q){
    return (q->front == ((q->rear+1)%(q->capacity)));
}

bool isEmpty(CircularQueue* q){
    return (q->front == -1);
}

void enqueue(CircularQueue* q, int x){
    if(isFull(q)) return;
    else if(isEmpty(q)){
        q->rear = 0;
        q->front = 0;
        q->arr[q->rear] = x;
    }
    else{
        q->rear = ((q->rear+1)%(q->capacity));
        q->arr[q->rear] = x;
    }
}

void dequeue(CircularQueue* q){
    if(isEmpty(q)) return;
    else if(q->rear == q->front){
        q->rear = -1;
        q->front = -1;
    }
    else{
        q->front = ((q->front+1)%(q->capacity));
    }
}

int getFront(CircularQueue* q){
    if(isEmpty(q)) return -1;
    else return(q->arr[q->front]);
}

int getRear(CircularQueue* q){
    if(isEmpty(q)) return -1;
    else return(q->arr[q->rear]);
}

void display(CircularQueue* q){
    if(isEmpty(q)) printf("Queue is Empty!");
    else{
        int i=q->front;
        while(true){
            printf("%d ",q->arr[i]);
            if(i==q->rear) break;
            i = (i+1)%q->capacity;
        }
    }
}