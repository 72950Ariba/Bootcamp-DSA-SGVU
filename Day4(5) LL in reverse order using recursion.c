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

// Function to insert a new node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Recursive function to print the linked list in reverse order
void printReverse(struct Node* head) {
    if (head == NULL)  // Base case: empty list
        return;
    
    printReverse(head->next);  // Recursive call to the next node
    printf("%d ", head->data);  // Print the data after returning from recursion
}

// Driver function to test the code
int main() {
    struct Node* head = NULL;

    // Inserting elements into the linked list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    printf("Linked list in reverse order: ");
    printReverse(head);  // Calling function to print in reverse

    return 0;
}
