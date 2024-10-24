#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the stack

// Stack structure with array and top variable
struct Stack {
    int arr[MAX];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;  // Set top to -1 to indicate the stack is empty
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
    } else {
        stack->top++;
        stack->arr[stack->top] = value;
        printf("Pushed %d to stack\n", value);
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;  // Return -1 to indicate underflow
    } else {
        int popped_value = stack->arr[stack->top];
        stack->top--;
        printf("Popped %d from stack\n", popped_value);
        return popped_value;
    }
}

// Function to peek at the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack->arr[stack->top];
    }
}

// Function to display the stack elements
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = stack->top; i >= 0; i--) {
            printf("%d\n", stack->arr[i]);
        }
    }
}

// Main function to demonstrate the stack operations
int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);

    pop(&stack);
    printf("Top element is %d\n", peek(&stack));

    display(&stack);

    return 0;
}
