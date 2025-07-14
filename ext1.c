#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
int count=0;

//Insert At First
void insertAtFirst(int data){
      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
      newNode->data=data;
      newNode->prev=NULL;
      newNode->next=head;
       count ++;
      if(head != NULL){
         head->prev=newNode;
      }
      head=newNode;
      return;
}
void reverseList(int ep) {
         struct Node* save = head;
    struct Node* current = head;
    struct Node* temp = NULL;
        int total=1;
        int flag=1;
while(flag==1)
{
        int i=1;
        while(i<=ep&&save->next!=NULL){
                save=save->next;
                i++;
        }
        if(i%ep==0){
        while (current != save) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
        }

       if (temp != NULL)
        head = temp->prev;
        }0
        0
        else{
                flag=0;
        }
}
    
}
void display(struct Node* src) {
    if (src == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = src;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int ch;

    do {
        printf("\n---------------------------\n");
        printf("1. Insert node\n");
        printf("2. display list\n");
        printf("3. reverse list \n");
        printf("0. Exit\n");
        printf("---------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                int n,i=1, data;
               printf("How many node ? ");
                scanf("%d", &n);
                while (i<=n) {
                    printf("Enter %d digit: ",i);
                    scanf("%d", &data);
                    insertAtFirst(data);
                    i++;
                }
                break;
            }

            case 2:
                printf("display list: ");
                display(head);
                break;

            case 3:{int k;
                 printf("Enter k:");
                 scanf("%d",&k);
                reverseList(k);
                printf("reverse completed.\n");
                break;}

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (ch != 0);

    return 0;
}
