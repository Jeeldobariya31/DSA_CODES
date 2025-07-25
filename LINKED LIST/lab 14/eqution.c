
#include <stdio.h>
#include <stdlib.h>

struct node {
    int co;
    int ex;
    struct node* link;
};

struct node* head1 = NULL;
struct node* head2 = NULL;
struct node* sumhead = NULL;

// Insert into Polynomial 1
void eq1(int co, int ex) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->co = co;
    newNode->ex = ex;
    newNode->link = NULL;

    if (head1 == NULL) {
        head1 = newNode;
        return;
    }

    struct node* temp = head1;
    while (temp->link != NULL)
        temp = temp->link;
    temp->link = newNode;
}

// Insert into Polynomial 2
void eq2(int co, int ex) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->co = co;
    newNode->ex = ex;
    newNode->link = NULL;

    if (head2 == NULL) {
        head2 = newNode;
        return;
    }

    struct node* temp = head2;
    while (temp->link != NULL)
        temp = temp->link;
    temp->link = newNode;
}

// Display polynomial
void display(struct node* src) {
    if (src == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = src;
    while (temp != NULL) {
        printf("%dx^%d", temp->co, temp->ex);
        if (temp->link != NULL) printf(" + ");
        temp = temp->link;
    }
    printf("= 0\n");
}

// Add polynomials
void addeq() {
    struct node* temp1 = head1;
    struct node* temp2 = head2;

    while (temp1 != NULL && temp2 != NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->link = NULL;

        if (temp1->ex > temp2->ex) {
            newNode->co = temp1->co;
            newNode->ex = temp1->ex;
            temp1 = temp1->link;
        } else if (temp1->ex < temp2->ex) {
            newNode->co = temp2->co;
            newNode->ex = temp2->ex;
            temp2 = temp2->link;
        } else {
            newNode->co = temp1->co + temp2->co;
            newNode->ex = temp1->ex;
            temp1 = temp1->link;
            temp2 = temp2->link;
        }

        if (sumhead == NULL) {
            sumhead = newNode;
        } else {
            struct node* temp = sumhead;
            while (temp->link != NULL)
                temp = temp->link;
            temp->link = newNode;
        }
    }

    while (temp1 != NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->co = temp1->co;
        newNode->ex = temp1->ex;
        newNode->link = NULL;

        struct node* temp = sumhead;
        if (temp == NULL) {
            sumhead = newNode;
        } else {
            while (temp->link != NULL)
                temp = temp->link;
            temp->link = newNode;
        }

        temp1 = temp1->link;
    }

    while (temp2 != NULL) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->co = temp2->co;
        newNode->ex = temp2->ex;
        newNode->link = NULL;

        struct node* temp = sumhead;
        if (temp == NULL) {
            sumhead = newNode;
        } else {
            while (temp->link != NULL)
                temp = temp->link;
            temp->link = newNode;
        }

        temp2 = temp2->link;
    }
    printf("Equations added successfully.\n");
}

// Main Menu
int main() {
    int ch;
    do {
        printf("\n------------------------\n");
        printf("=> Your equation's exponents should be in ascending order.\n");
        printf("1. Scan Equation-1\n");
        printf("2. Scan Equation-2\n");
        printf("3. Display Equation-1\n");
        printf("4. Display Equation-2\n");
        printf("5. Add Equations\n");
        printf("6. Display Final (Sum) Equation\n");
        printf("0. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                int turm, i, co, ex;
                printf("How many terms in Equation-1? ");
                scanf("%d", &turm);
                for (i = 1; i <= turm; i++) {
                    printf("Enter %d term's coefficient: ",i);
                    scanf("%d", &co);
                    printf("Enter %d term's exponent: ",i);
                    scanf("%d", &ex);
                    eq1(co, ex);
                }
                break;
            }
            case 2: {
                int turm, i, co, ex;
                printf("How many terms in Equation-2? ");
                scanf("%d", &turm);
                for (i = 1; i <= turm; i++) {
                    printf("Enter %d term's coefficient: ",i);
                    scanf("%d", &co);
                    printf("Enter %d term's exponent: ",i);
                    scanf("%d", &ex);
                    eq2(co, ex);
                }
                break;
            }
            case 3:
                printf("Equation 1: ");
                display(head1);
                break;

            case 4:
                printf("Equation 2: ");
                display(head2);
                break;

            case 5:
                addeq();
                break;

            case 6:
                printf("Final Equation (Sum): ");
                display(sumhead);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice. Try again.\n");
        }

    } while (ch != 0);

    return 0;
}



