#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10  // Maximum number of actions that can be stored

// Stack structure
struct Stack {
    char actions[MAX][50];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push an action onto the stack
void push(struct Stack* stack, char action[]) {
    if (isFull(stack)) {
        printf("Action stack is full, cannot perform more actions.\n");
    } else {
        stack->top++;
        strcpy(stack->actions[stack->top], action);
    }
}

// Function to pop an action from the stack
char* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("No actions to undo.\n");
        return NULL;
    } else {
        return stack->actions[stack->top--];
    }
}

// Function to display the current state of the text
void displayText(char text[]) {
    printf("Current text: %s\n", text);
}

int main() {
    struct Stack undoStack;
    char text[100] = "";  // Text buffer to store the current state of text

    initialize(&undoStack);

    // Simulate some actions
    char action1[] = "Typed 'Hello'";
    char action2[] = "Typed ' World'";
    char action3[] = "Deleted ' World'";

    // Simulating typing "Hello"
    strcat(text, "Hello");
    push(&undoStack, action1);
    displayText(text);

    // Simulating typing " World"
    strcat(text, " World");
    push(&undoStack, action2);
    displayText(text);

    // Simulating deleting " World"
    text[strlen(text) - 6] = '\0';  // Remove ' World'
    push(&undoStack, action3);
    displayText(text);

    // Undo last action
    printf("\nUndoing action: %s\n", pop(&undoStack));
    strcat(text, " World");  // Undo delete
    displayText(text);

    // Undo another action
    printf("\nUndoing action: %s\n", pop(&undoStack));
    text[strlen(text) - 6] = '\0';  // Remove ' World' again
    displayText(text);

    return 0;
}
