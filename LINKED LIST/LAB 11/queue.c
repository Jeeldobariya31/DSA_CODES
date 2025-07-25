#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue() {
    int value;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &value);
    new_node->data = value;
    new_node->link = NULL;

    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->link = new_node;
        rear = new_node;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("QUEUE is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeued element: %d\n", temp->data);
    struct Node * Save=rear;
    while(Save->link!=front){
        save=save->link;
    }
    front = Save;
    
    free(temp);
}

void peek() {
    if (front == NULL) {
        printf("QUEUE is empty.\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

void display() {
    if (front == NULL) {
        printf("QUEUE is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Current QUEUE: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    do {
        printf("\n=== QUEUE OPERATIONS ===\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek (Front Element)\n");
        printf("4. Display Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 0: printf("Exiting program.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
