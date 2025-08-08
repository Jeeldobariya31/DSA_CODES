#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct ele {
    int data;
    int prio;
};

struct ele queue[SIZE];
int Front = -1;
int Rear = -1;

// Enqueue 
void enqueue(int x, int y) {
    if (Rear >= SIZE - 1) {
        printf("Queue overflow..\n");
        return;
    }

    struct ele temp;
    temp.data = x;
    temp.prio = y;

    if (Front == -1) { 
        Front = Rear = 0;
        queue[Rear] = temp;
        return;
    }
    int i;
    for (i = Rear; i >= Front && queue[i].prio < temp.prio; i--) {
        queue[i + 1] = queue[i];
    }
    queue[i + 1] = temp;
    Rear++;
}

// Dequeue 
void dequeue() {
    if (Front == -1) {
        printf("Queue underflow..\n");
        return;
    }
    printf("Dequeued: Data=%d Priority=%d\n", queue[Front].data, queue[Front].prio);

    if (Front == Rear) { 
        Front = Rear = -1;
    } else {
        Front++;
    }
}

// Display 
void display() {
    if (Front == -1) {
        printf("Queue is empty..\n");
        return;
    }
    printf("Queue (Data, Priority):\n");
    for (int i = Front; i <= Rear; i++) {
        if (i == Rear) {
            printf("(%d, %d)", queue[i].data, queue[i].prio);
        } else {
            printf("(%d, %d), ", queue[i].data, queue[i].prio);
        }
    }
    printf("\n");
}

int main() {
    int ch, val, p;
    do {
        printf("\n====== Priority Queue Menu ======\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Remove)\n");
        printf("3. Display Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &val);
                printf("Enter priority: ");
                scanf("%d", &p);
                enqueue(val, p);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (ch != 0);

    return 0;
}
