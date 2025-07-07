#include <stdio.h>
#include <stdlib.h>

// Node definition for singly linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert node at front
void insertFront(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Insert node at end
void insertEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Delete first node
void deleteFront() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete last node
void deleteLast() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

// Delete node from a specified position
void deleteAtPosition(int pos) {
    if (head == NULL || pos < 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        deleteFront();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

// Display all nodes
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Count number of nodes
int countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Copy a linked list
struct Node* copyList(struct Node* src) {
    if (src == NULL) return NULL;
    struct Node* newHead = createNode(src->data);
    struct Node* tail = newHead;
    src = src->next;
    while (src != NULL) {
        tail->next = createNode(src->data);
        tail = tail->next;
        src = src->next;
    }
    return newHead;
}

// Reverse a linked list
void reverseList() {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Compare two linked lists
int areSame(struct Node* list1, struct Node* list2) {
    while (list1 && list2) {
        if (list1->data != list2->data)
            return 0;
        list1 = list1->next;
        list2 = list2->next;
    }
    return (list1 == NULL && list2 == NULL);
}

// Remove duplicates from sorted list
void removeDuplicates() {
    struct Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        } else {
            current = current->next;
        }
    }
}

// Swap kth node from start with kth from end
void swapKth(int k) {
    int n = countNodes();
    if (k > n || k < 1 || 2 * k - 1 == n) return;

    struct Node *x = head, *x_prev = NULL;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }

    struct Node *y = head, *y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++) {
        y_prev = y;
        y = y->next;
    }

    if (x_prev) x_prev->next = y;
    if (y_prev) y_prev->next = x;

    struct Node* temp = x->next;
    x->next = y->next;
    y->next = temp;

    if (k == 1) head = y;
    if (k == n) head = x;
}
//Short Linked list
void shortlist() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    printf("=> List Sorted Successfully.\n");
}


// Menu-driven program
void menu() {
    int choice, data, pos, k;
    do {
        printf("\n---- Singly Linked List Menu ----\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete First Node\n");
        printf("4. Delete Last Node\n");
        printf("5. Delete at Position\n");
        printf("6. Display List\n");
        printf("7. Count Nodes\n");
        printf("8. Reverse List\n");
        printf("9. Copy List\n");
        printf("10. Compare with Copied List\n");
        printf("11. Remove Duplicates (sorted list)\n");
        printf("12. Swap Kth Node from Start and End\n");
        printf("13. Short List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Total nodes: %d\n", countNodes());
                break;
            case 8:
                reverseList();
                break;
            case 9: {
                struct Node* copy = copyList(head);
                printf("Copied list: ");
                struct Node* temp = copy;
                while (temp != NULL) {
                    printf("%d -> ", temp->data);
                    temp = temp->next;
                }
                printf("NULL\n");
                break;
            }
            case 10: {
                struct Node* copy = copyList(head);
                printf("Lists are %s\n", areSame(head, copy) ? "same" : "different");
                break;
            }
            case 11:
                removeDuplicates();
                break;
            case 12:
                printf("Enter value of K: ");
                scanf("%d", &k);
                swapKth(k);
                break;
            case 13:
               shortlist();
                break;    
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}