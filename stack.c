#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

struct Stack
{
    int arr[MAX_SIZE];
    int top;
};

void init(struct Stack *stack)
{
    stack->top = -1;
}

bool isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

bool isFull(struct Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

void push (struct Stack *stack, int data) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", data);
    } else {
        stack->top++;
        stack->arr[stack->top] = data;
        printf("%d pushed to stack\n", data);
    }
}

void pop(struct Stack *stack) {
    if (isEmpty(stack))
    {
        printf("Stack underflow!\n");
    }
    else
    {
        printf("%d popped from stack\n", stack->arr[stack->top]);
        stack->top--;
    }
    
    
}

void top (struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element is %d\n", stack->arr[stack->top]);
    }
}

int main()
{
    struct Stack stack;
    init(&stack);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    top(&stack);
    pop(&stack);
    top(&stack);
    return 0;
}
