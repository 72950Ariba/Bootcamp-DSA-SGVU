#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void insertFront(int element) {
    if (isFull()) {
        printf("Deque is Full\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front == 0) ? SIZE - 1 : front - 1;
    }
    deque[front] = element;
    printf("%d inserted at front\n", element);
}

void insertRear(int element) {
    if (isFull()) {
        printf("Deque is Full\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    deque[rear] = element;
    printf("%d inserted at rear\n", element);
}

void deleteFront() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }
    printf("%d deleted from front\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }
    printf("%d deleted from rear\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear == 0) ? SIZE - 1 : rear - 1;
    }
}

void display() {
    if (isEmpty()) {
        printf("Deque is Empty\n");
        return;
    }
    printf("Deque: ");
    for (int i = front; i != rear; i = (i + 1) % SIZE) {
        printf("%d ", deque[i]);
    }
    printf("%d\n", deque[rear]);
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(30);
    display();
    deleteFront();
    display();
    return 0;
}
