#include<stdio.h>
#include<stdlib.h>
typedef struct STACK{
    int* arr;
    int capacity;
    int topIndex;
}STACK;

STACK* createStack(int n){
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->capacity = n;
    stack->topIndex = -1;
    stack->arr = (int*)malloc(n*sizeof(int));
    return stack;
}

void push(STACK* stack, int num){
    if(stack->topIndex == (stack->capacity)-1) return;
    stack->topIndex++;
    stack->arr[stack->topIndex] = num;
}

void minStack(STACK* stack,int n){
    int minimum = stack->arr[0];
    for(int i=0;i<n;i++){
        if(minimum>stack->arr[i]) minimum = stack->arr[i];
    }
    printf("%d",minimum);
}
int main(){
    int n;
    printf("Enter the capacity of stack: \n");
    scanf("%d",&n);
    STACK* stack = createStack(n);
    printf("Enter the stack elements: ");
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        push(stack,arr[i]);
    }
    
    printf("MINIMUM NUMBER IN STACK: \n");
    minStack(stack,n);
}