#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;


//Insert At First
void insertAtFirst(){
      int data;
      printf("Enter Value :");
      scanf("%d",&data);

      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
      newNode->data=data;
      newNode->prev=NULL;
      newNode->next=head;

      if(head != NULL){
         head->prev=newNode;
      }
      head=newNode;
      return;
}
//display forward
void displayForward() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("List (forward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//delate alter
void delalter() {
    if (head == NULL) {
        printf("=> List is already empty.\n");
        return;
    }

    struct Node* current = head;
    int i = 1;

    while (current != NULL && current->next != NULL) {
        struct Node* temp = current->next;
        current->next = temp->next;

        if (temp->next != NULL) {
            temp->next->prev = current;
        }

        free(temp);
        current = current->next;
        i++;
    }

    printf("=> Alternate nodes deleted successfully.\n");
}

int main(){
        int ch;
        do{
                 printf("=> 1.For insert at first\n");
                 printf("=> 2.For Display list\n");
                 printf("=> 3.For delate alter node\n");
                 printf("=>  0.For Exit\n");
                 printf("ENter Choice :");
                 scanf("%d",&ch);
                 switch(ch){
                        case 1:insertAtFirst();break;
                        case 2:displayForward();break;
                        case 3:delalter();break;
                        default:printf("Invalied Choice...");break;
                 };
        }while(ch!=0);
        return 0;
}