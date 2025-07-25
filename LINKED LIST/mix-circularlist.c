#include <stdio.h>
#include <stdlib.h>
// Circular Linked List Node
struct Node {
    int data;
    struct Node* link;
};

// Head and Tail pointers

struct Node* FIRST = NULL;
struct Node* LAST = NULL;

// Insert at front

void insertAtFront() {
    struct Node* NEW = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &NEW->data);
    NEW->link = NULL;

    if (FIRST == NULL) {
        NEW->link = NEW;
        FIRST = LAST = NEW;
    } else {
        NEW->link = FIRST;
        LAST->link = NEW;
        FIRST = NEW;
    }
}
// Insert at end
void insertAtLast() {
    struct Node* NEW = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &NEW->data);
    NEW->link = NULL;

    if (FIRST == NULL) {
        NEW->link = NEW;
        FIRST = LAST = NEW;
    } else {
        NEW->link = FIRST;
        LAST->link = NEW;
        LAST = NEW;
    }
}
// Insert in sorted order
void insertSorted() {
    struct Node* NEW = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &NEW->data);
    NEW->link = NULL;

    if (FIRST == NULL) {
        NEW->link = NEW;
        FIRST = LAST = NEW;
        return;
    }

    if (NEW->data <= FIRST->data) {
        NEW->link = FIRST;
        LAST->link = NEW;
        FIRST = NEW;
        return;
    }

    struct Node* SAVE = FIRST;
    while (SAVE != LAST && NEW->data >= SAVE->link->data) {
        SAVE = SAVE->link;
    }

    NEW->link = SAVE->link;
    SAVE->link = NEW;

    if (SAVE == LAST) {
        LAST = NEW;
    }
}
// Insert at specific position

void insertAtPosition() {
    int pos, val, count = 1;
    printf("Enter position to insert at: ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &val);

    struct Node* NEW = (struct Node*)malloc(sizeof(struct Node));
    NEW->data = val;
    NEW->link = NULL;

    if (FIRST == NULL || pos <= 1) {
        NEW->link = (FIRST == NULL) ? NEW : FIRST;
        if (FIRST == NULL) {
            FIRST = LAST = NEW;
        } else {
            LAST->link = NEW;
            FIRST = NEW;
        }
        return;
    }

    struct Node* temp = FIRST;
    while (count < pos - 1 && temp->link != FIRST) {
        temp = temp->link;
        count++;
    }

    NEW->link = temp->link;
    temp->link = NEW;

    if (temp == LAST) {
        LAST = NEW;
    }
}
// Delete node by value
void deleteByValue() {
    if (FIRST == NULL) {
        printf("List is empty.\n");
        return;
    }

    int x;
    printf("Enter value to delete: ");
    scanf("%d", &x);

    struct Node* SAVE = FIRST;
    struct Node* PRED = NULL;

    while (SAVE->data != x && SAVE != LAST) {
        PRED = SAVE;
        SAVE = SAVE->link;
    }

    if (SAVE->data != x) {
        printf("Node not found.\n");
        return;
    }

    if (SAVE == FIRST) {
        if (FIRST == LAST) {
            free(FIRST);
            FIRST = LAST = NULL;
            return;
        }
        FIRST = FIRST->link;
        LAST->link = FIRST;
    } else {
        PRED->link = SAVE->link;
        if (SAVE == LAST) {
            LAST = PRED;
        }
    }

    free(SAVE);
    printf("Node with value %d deleted.\n", x);
}

// Delete node at specific position
void deleteAtPosition() {
    if (FIRST == NULL) {
        printf("List is empty.\n");
        return;
    }

    int pos, count = 1;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos == 1) {
        struct Node* temp = FIRST;

        if (FIRST == LAST) {
            FIRST = LAST = NULL;
        } else {
            FIRST = FIRST->link;
            LAST->link = FIRST;
        }

        printf("Deleted node at position 1 with value %d.\n", temp->data);
        free(temp);
        return;
    }

    struct Node* current = FIRST;
    struct Node* previous = NULL;

    while (count < pos && current->link != FIRST) {
        previous = current;
        current = current->link;
        count++;
    }

    if (count != pos) {
        printf("Invalid position!\n");
        return;
    }

    previous->link = current->link;

    if (current == LAST) {
        LAST = previous;
    }

    printf("Deleted node at position %d with value %d.\n", pos, current->data);
    free(current);
}

// Display circular linked list
void display() {
    if (FIRST == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = FIRST;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->link;
    } while (temp != FIRST);
    printf("(HEAD)\n");
}

// Main function
int main() {
    int choice;
    do {
        printf("\n== Main Menu ==\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert in Sorted Order\n");
        printf("4. Display List\n");
        printf("5. Delete Node by Value\n");
        printf("6. Insert at Specific Position\n");
        printf("7. Delete Node at Specific Position\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtFront(); break;
            case 2: insertAtLast(); break;
            case 3: insertSorted(); break;
            case 4: display(); break;
            case 5: deleteByValue(); break;
            case 6: insertAtPosition(); break;
            case 7: deleteAtPosition(); break;
            case 0: printf("Exiting program...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
