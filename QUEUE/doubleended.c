#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;


int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}


int isEmpty() {
    return (front == -1);
}

// Insert at front
void insertFront(int val) {
    if (isFull()) {
        printf("Deque overflow!\n");
        return;
    }
    if (isEmpty()) { // first element
        front = rear = 0;
    }
    else if (front == 0) {
        front = SIZE - 1;
    }
    else {
        front--;
    }
    deque[front] = val;
    printf("Inserted %d at front.\n", val);
}

// Insert at rear
void insertRear(int val) {
    if (isFull()) {
        printf("Deque overflow!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    }
    else if (rear == SIZE - 1) {
        rear = 0;
    }
    else {
        rear++;
    }
    deque[rear] = val;
    printf("Inserted %d at rear.\n", val);
}

// Delete from front
void deleteFront() {
    if (isEmpty()) {
        printf("Deque underflow!\n");
        return;
    }
    printf("Deleted %d from front.\n", deque[front]);

    if (front == rear) { // only one element
        front = rear = -1;
    }
    else if (front == SIZE - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

// Delete from rear
void deleteRear() {
    if (isEmpty()) {
        printf("Deque underflow!\n");
        return;
    }
    printf("Deleted %d from rear.\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = SIZE - 1;
    }
    else {
        rear--;
    }
}

// Display deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, val;
    do {
        printf("\n===== Double Ended Queue Menu =====\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Deque\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
       scanf("%d", &choice)'' 
        
        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
