#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

char queue[SIZE];
int front = -1, rear = -1;

void enqueue(char val) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue overflow (circular)...\n");
        return;
    }

    if (front == -1) { 
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = val;
}

char dequeue() {
    if (front == -1) {
        printf("Queue underflow (circular)...\n");
        return '\0';
    }

    char val = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    return val;
}

char peek() {
    if (front == -1) {
        printf("Queue is empty...\n");
        return '\0';
    }

    return queue[front];
}

void display() {
    if (front == -1) {
        printf("Queue is empty...\n");
        return;
    }

    printf("Queue is: ");
    int i = front;
    while (1) {
        printf("%c", queue[i]);
        if (i == rear){
            break;
        }
        printf(", ");
        i = (i + 1) % SIZE;
    }
    printf("\nPrinting completed.....\n");
}

int main() {
    int ch;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n0. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                char ele;
                printf("Enter element to enqueue: ");
                scanf(" %c", &ele);
                enqueue(ele);
                break;
            }
            case 2: {
                char ele = dequeue();
                if (ele != '\0')
                    printf("Dequeued element is %c.\n", ele);
                break;
            }
            case 3: {
                char ele = peek();
                if (ele != '\0')
                    printf("Front element is %c.\n", ele);
                break;
            }
            case 4:
                display();
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice...\n");
        }
    } while (ch != 0);

    return 0;
}
