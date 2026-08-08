//Time Complexity = O(1) for push,pop,peek,isEmpty,size operations
//Space Complexity = O(n) as one node per element is created
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node{
    int data;
    Node* next;
}Node;

typedef struct myStack{
    Node* top;
    int size;
}myStack;

Node* createNode(int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void initStack(myStack* s){
    s->top = NULL;
    s->size = 0;
}

bool isEmpty(myStack* s){
    return(s->top==NULL);
}

int peek(myStack* s){
    if(s->top==NULL) return -1;
    return (s->top->data);
}

int size(myStack* s){
    return(s->size);
}

void push(myStack* s, int x){
    Node* newNode = createNode(x);
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

void pop(myStack* s){
    if(isEmpty(s)==true) return;
    Node* temp = s->top;
    s->top = s->top->next;
    s->size--;
    free(temp);
}

