#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head1 = NULL;
struct node* head2 = NULL;
struct node* sumhead = NULL;
int len1 = 0, len2 = 0;

// Insert digit into number 1
void num1(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    len1++;

    if (head1 == NULL) {
        head1 = newNode;
        return;
    }

    struct node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert digit into number 2
void num2(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    len2++;

    if (head2 == NULL) {
        head2 = newNode;
        return;
    }

    struct node* temp = head2;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}


void insertAtFirst(struct node** head, int* len) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = 0;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
    (*len)++;
}

// set  leading zeros
void setZero() {
    while (len1 < len2)
        insertAtFirst(&head1, &len1);
    while (len2 < len1)
        insertAtFirst(&head2, &len2);
}

// Display 
void display(struct node* src) {
    if (src == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = src;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Sum the two numbers 
void sum() {
  
    setZero();

    struct node* temp1 = head1;
    struct node* temp2 = head2;

    
    while (temp1 && temp1->next) temp1 = temp1->next;
    while (temp2 && temp2->next) temp2 = temp2->next;

    int carry = 0;

   
    while (temp1 != NULL && temp2 != NULL) {
        int s = temp1->data + temp2->data + carry;
        carry = s / 10;
        s = s % 10;

     
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = s;
        newNode->prev = NULL;
        newNode->next = sumhead;

        if (sumhead != NULL)
            sumhead->prev = newNode;

        sumhead = newNode;

        temp1 = temp1->prev;
        temp2 = temp2->prev;
    }

    //  carry left, add it
    if (carry > 0) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = carry;
        newNode->prev = NULL;
        newNode->next = sumhead;
        if (sumhead != NULL)
            sumhead->prev = newNode;
        sumhead = newNode;
    }
}

int main() {
    int ch;

    do {
        printf("\n---------------------------\n");
        printf("1. Insert digits for Number 1\n");
        printf("2. Insert digits for Number 2\n");
        printf("3. Display Number 1\n");
        printf("4. Display Number 2\n");
        printf("5. Add the two numbers\n");
        printf("6. Display the Sum\n");
        printf("0. Exit\n");
        printf("---------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                int n,i=1, data;
               printf("How many digits for Number 1? ");
                scanf("%d", &n);
                printf("Enter digits from last (unit's place first):\n");
                while (i<=n) {
                    printf("Enter %d digit: ",i);
                    scanf("%d", &data);
                    num1(data);
                    i++;
                }
                break;
            }

            case 2: {
                int n,i=1, data;
                printf("How many digits for Number 2? ");
                scanf("%d", &n);
              
                 while (i<=n) {
                    printf("Enter %d digit: ",i);
                    scanf("%d", &data);
                    num2(data);
                    i++;
                }
                break;
            }

            case 3:
                printf("Number 1: ");
                display(head1);
                break;

            case 4:
                printf("Number 2: ");
                display(head2);
                break;

            case 5:
                sum();
                printf("Addition completed.\n");
                break;

            case 6:
                printf("Sum: ");
                display(sumhead);
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (ch != 0);

    return 0;
}
