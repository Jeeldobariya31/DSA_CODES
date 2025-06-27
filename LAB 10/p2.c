#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* First = NULL;

void addAtEnd() {
    int value;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &value);
    new_node->data = value;
    new_node->link = NULL;

    if (First == NULL) {
        First = new_node;
    } else {
        struct Node* temp = First;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = new_node;
    }
}

void addAtFirst() {
    int value;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &value);
    new_node->data = value;
    new_node->link = First;
    First = new_node;
}

void addAtPosition() {
    int count = 0, pos, i = 1;
    struct Node* temp = First;

    while (temp != NULL) {
        count++;
        temp = temp->link;
    }

    printf("Total nodes = %d\n", count);
    printf("Enter position after which to insert (0 to %d): ", count);
    scanf("%d", &pos);

    if (pos < 0 || pos > count) {
        printf("Invalid position\n");
        return;
    }

    int value;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &value);
    new_node->data = value;

    if (pos == 0) {
        new_node->link = First;
        First = new_node;
    } else {
        temp = First;
        for (i = 1; i < pos; i++) {
            temp = temp->link;
        }
        new_node->link = temp->link;
        temp->link = new_node;
    }
}

void printList() {
    struct Node* temp = First;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Current Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void countNodes() {
    int count = 0;
    struct Node* temp = First;
    while (temp != NULL) {
        count++;
        temp = temp->link;
    }
    printf("Total nodes = %d\n", count);
}

void deleteAtStart() {
    if (First == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = First;
    First = First->link;
    free(temp);
}

void deleteAtEnd() {
    if (First == NULL) {
        printf("List is empty.\n");
    } else if (First->link == NULL) {
        free(First);
        First = NULL;
    } else {
        struct Node* temp = First;
        while (temp->link->link != NULL) {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
}

void deleteAtPosition() {
    int pos, i;
    int count = 0;
    struct Node* temp = First;

    while (temp != NULL) {
        count++;
        temp = temp->link;
    }

    printf("Total nodes = %d\n", count);
    printf("Enter position to delete (1 to %d): ", count);
    scanf("%d", &pos);

    if (pos < 1 || pos > count) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        temp = First;
        First = First->link;
        free(temp);
    } else {
        temp = First;
        for (i = 1; i < pos - 1; i++) {
            temp = temp->link;
        }
        struct Node* del = temp->link;
        temp->link = del->link;
        free(del);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nEnter \n1. Add at End\n2. Add at First\n3. Add at Any Position\n4. Print list\n5. Count nodes");
        printf("\n6. Delete at Start\n7. Delete at End\n8. Delete at Any Position\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addAtEnd(); break;
            case 2: addAtFirst(); break;
            case 3: addAtPosition(); break;
            case 4: printList(); break;
            case 5: countNodes(); break;
            case 6: deleteAtStart(); break;
            case 7: deleteAtEnd(); break;
            case 8: deleteAtPosition(); break;
            case 0: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
