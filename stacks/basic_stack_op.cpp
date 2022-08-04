#include <iostream>
using namespace std;

struct stack {
    int limit, top;
    int *arr;    
};

struct stack * newStack(int limit) {
    struct stack * temp = (struct stack *)malloc(sizeof(struct stack));
    temp->limit=limit;
    temp->top = -1;
    temp->arr = (int *)malloc(sizeof(int) * limit);
    return temp;
}

int isFull(struct stack * stack) {
    return stack->top == stack->limit - 1;
}

int isEmpty(struct stack * stack) {
    return stack->top == -1;
}

struct stack * push(struct stack *stack, int val) {
    if(!isFull(stack)) {
        stack->arr[++stack->top] = val;
    }
    return stack;
}

struct stack * pop(struct stack * stack) {
    if(!isEmpty(stack)) stack->top--;
    return stack;
}

void peek(struct stack * stack) {
    cout<<stack->arr[stack->top]<<endl;
}

int main(){
    struct stack * stack1 = newStack(5);
    for(int i=0;i<8;i++) {
        stack1 = push(stack1, i);
    }
    for(int i=0;i<5;i++){
        peek(stack1);
        stack1 = pop(stack1);
    }
    return 0;
}
