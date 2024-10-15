#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the queue

// Queue structure
struct Queue {
    int items[MAX];  // Array to store queue elements
    int front, rear; // Indices to track front and rear of the queue
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Check if the queue is full
int isFull(struct Queue* q) {
    return (q->rear == MAX - 1);
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

// Enqueue (insert element to queue)
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
        return;
    }
    
    if (q->front == -1) {
        q->front = 0;  // Initialize front if it's the first element
    }
    
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued %d to the queue.\n", value);
}

// Dequeue (remove element from queue)
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }

    int dequeued = q->items[q->front];
    printf("Dequeued %d from the queue.\n", dequeued);
    q->front++;

    // If the queue becomes empty after dequeuing
    if (q->front > q->rear) {
        q->front = q->rear = -1;  // Reset queue
    }

    return dequeued;
}

// Display the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main() {
    struct Queue* q = createQueue();

    // Perform some enqueue operations
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);  // Output: Queue elements: 10 20 30

    // Perform some dequeue operations
    dequeue(q);
    display(q);  // Output: Queue elements: 20 30

    dequeue(q);
    dequeue(q);
    dequeue(q);  // Queue is empty now

    // Try to dequeue from empty queue
    dequeue(q);

    // Enqueue more elements
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);  // Output: Queue elements: 40 50

    return 0;
}
