#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Deque structure
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to create a deque
struct Deque* createDeque() {
    struct Deque* dq = (struct Deque*)malloc(sizeof(struct Deque));
    dq->front = dq->rear = NULL;
    return dq;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* dq) {
    return (dq->front == NULL);
}

// Insert at front
void insertFront(struct Deque* dq, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        newNode->next = dq->front;
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    printf("%d inserted at front\n", data);
}

// Insert at rear
void insertRear(struct Deque* dq, int data) {
    struct Node* newNode = createNode(data);
    if (isEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        dq->rear->next = newNode;
        newNode->prev = dq->rear;
        dq->rear = newNode;
    }
    printf("%d inserted at rear\n", data);
}

// Delete from front
int deleteFront(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque Underflow\n");
        return -1;
    }
    struct Node* temp = dq->front;
    int data = temp->data;

    if (dq->front == dq->rear) {  // If only one element
        dq->front = dq->rear = NULL;
    } else {
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }
    free(temp);
    return data;
}

// Delete from rear
int deleteRear(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque Underflow\n");
        return -1;
    }
    struct Node* temp = dq->rear;
    int data = temp->data;

    if (dq->front == dq->rear) {  // If only one element
        dq->front = dq->rear = NULL;
    } else {
        dq->rear = dq->rear->prev;
        dq->rear->next = NULL;
    }
    free(temp);
    return data;
}

// Get front element
int getFront(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->front->data;
}

// Get rear element
int getRear(struct Deque* dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->rear->data;
}

// Driver program to test deque implementation
int main() {
    struct Deque* dq = createDeque();
    insertRear(dq, 10);
    insertRear(dq, 20);
    insertFront(dq, 5);

    printf("Front element is %d\n", getFront(dq));
    printf("Rear element is %d\n", getRear(dq));

    printf("%d deleted from front\n", deleteFront(dq));
    printf("Front element is now %d\n", getFront(dq));

    return 0;
}
