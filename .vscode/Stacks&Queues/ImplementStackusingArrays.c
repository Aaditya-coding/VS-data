//Stack contains only similar data-types
//Time Complexity = O(1) of all the functions
//Space Complexity = O(n) overall because array is used to store data
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    int*arr;
    int capacity;
    int topIndex;
}myStack;

myStack* createStack(int n){
    myStack* s = (myStack*)malloc(1*sizeof(myStack));
    s->capacity = n;
    s->topIndex = -1;
    s->arr = (int*)malloc(n*sizeof(int));
    return s;
}

int isEmpty(myStack* stack){
    int ans = stack->topIndex;
    if(ans==-1) return 1;
    return 0;
}

int isFull(myStack* stack){
    int ans = stack->topIndex;
    if(ans==(stack->capacity)-1) return 1;
    return 0;
}

int peek(myStack* stack){
    if(stack->topIndex == -1) return -1; 
    return stack->arr[stack->topIndex];
}

void push(myStack* stack, int x){
    if(stack->topIndex == (stack->capacity)-1) return;
    stack->topIndex++;
    stack->arr[stack->topIndex] = x;
}

void pop(myStack* stack){
    if(stack->topIndex == -1) return;
    stack->topIndex--;
}