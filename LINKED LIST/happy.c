#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

void insertAtEnd(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
        return;
    }
}

void happy(int n) {
    int flag = 1;
    int copyn=n;
    while (flag == 1) {
        int ans = 0, rim;
        int temp_n = n;

        while (temp_n != 0) {
            rim = temp_n % 10;
            ans += rim * rim;
            temp_n /= 10;
        }

        if (ans == 1) {
            printf("%d is a Happy Number!\n", copyn);
            return;
        }
        struct node* temp = head;
        while (temp->next != NULL) {
            if (temp->data == ans) {
                printf("%d is NOT a Happy Number.\n", copyn);
                return;
            }
            temp = temp->next;
        }

        insertAtEnd(ans);
        n = ans;
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    insertAtEnd(num);
    happy(num);

    return 0;
}
