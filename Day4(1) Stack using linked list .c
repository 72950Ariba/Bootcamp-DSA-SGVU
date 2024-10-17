#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Function to push an element onto the stack
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;  // Link the new node with the previous top
    *top = newNode;        // Update the top pointer
    printf("%d pushed onto stack\n", data);
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow\n");
        return -1;  // Return -1 when stack is empty
    }
    struct Node* temp = *top;
    *top = (*top)->next;  // Update top to point to the next node
    int popped = temp->data;
    free(temp);  // Free memory
    return popped;
}

// Function to peek the top element of the stack
int peek(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Driver program to test the stack implementation
int main() {
    struct Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is %d\n", peek(stack));

    printf("%d popped from stack\n", pop(&stack));
    printf("Top element is %d\n", peek(stack));

    return 0;
}
