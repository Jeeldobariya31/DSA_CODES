#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == SIZE - 1) {
        printf("Queue overflow...\n");
    } else {
        if (front == -1)
            front = 0;
        queue[++rear] = val;
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow...\n");
        return -1;
    } else {
        return queue[front++];
    }
}

int peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty...\n");
        return -1;
    } else {
        return queue[front];
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty...\n");
    } else {
        printf("Queue is: ");
        for (int i = front; i <= rear; i++) {
            printf("%d", queue[i]);
            if (i < rear) printf(", ");
        }
        printf("\nPrinting completed.....\n");
    }
}

int main() {
    int ch;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n0. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                int ele;
                printf("Enter element to enqueue: ");
                scanf("%d", &ele);
                enqueue(ele);
                break;
            }
            case 2: {
                int ele = dequeue();
                if (ele != -1)
                    printf("Dequeued element is %d.\n", ele);
                break;
            }
            case 3: {
                int ele = peek();
                if (ele != -1)
                    printf("Front element is %d.\n", ele);
                break;
            }
            case 4:
                display();
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice......\n");
        }
    } while (ch != 0);

    return 0;
}
