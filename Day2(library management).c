#include <stdio.h>
#include <stdlib.h>

// Queue node to hold the floor requests
struct Node {
    int floor;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int floor) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->floor = floor;
    temp->next = NULL;
    return temp;
}

// Queue structure
struct Queue {
    struct Node *front, *rear;
};

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue (add a request)
void enqueue(struct Queue* q, int floor) {
    struct Node* temp = newNode(floor);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
    printf("Lift requested at floor %d.\n", floor);
}

// Dequeue (remove and return the next request)
int dequeue(struct Queue* q) {
    if (q->front == NULL)
        return -1;
    struct Node* temp = q->front;
    int floor = temp->floor;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return floor;
}

// Function to move the lift and serve the requests
void moveLift(struct Queue* q, int total_floors) {
    int current_floor = 0;
    int next_floor;

    if (q->front == NULL) {
        printf("No requests to process.\n");
        return;
    }

    while ((next_floor = dequeue(q)) != -1) {
        printf("Moving from floor %d to floor %d.\n", current_floor, next_floor);
        
        while (current_floor != next_floor) {
            if (next_floor > current_floor) {
                current_floor++;
            } else {
                current_floor--;
            }
            printf("Lift at floor %d.\n", current_floor);
        }

        printf("Lift has arrived at floor %d.\n", next_floor);
    }
}

int main() {
    struct Queue* q = createQueue();
    int total_floors = 10;

    // Simulating lift requests
    enqueue(q, 3);
    enqueue(q, 7);
    enqueue(q, 1);

    // Processing the lift movement
    moveLift(q, total_floors);

    return 0;
}
