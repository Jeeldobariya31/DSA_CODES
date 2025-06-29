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

// Insert at End

void insertAtEnd(){
int data;
      printf("Enter Value :");
      scanf("%d",&data);

      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
      newNode->data=data;
      newNode->prev=NULL;
      newNode->next=NULL;
      if(head == NULL){
         head=newNode;
         return;
      }
      else{
        struct Node* temp = head;

        while(temp->next!=NULL){
                temp=temp->next;
        }

        temp->next=newNode;
        newNode->prev=temp;
         return;
      }
}
// Insert At Position
void insertAtPosition(){
        int data, pos;
     printf("Enter Value : ");
     scanf("%d", &data);
      printf("Enter position: ");
        scanf("%d", &pos);

      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
      newNode->data=data;
      newNode->prev=NULL;
      newNode->next=NULL;

      if(head==NULL){
        head=newNode;
      }
      else{      //insert at start
                if (pos == 1) 
                {
                  newNode->next = head;
                  head->prev = newNode;
                   head = newNode;
                     return;
                }else
                {
                         // Traverse to position - 1
                       struct Node* temp = head;
                       for (int i = 1; temp != NULL && i < pos - 1; i++){
                       temp = temp->next;
                       }

                       newNode->next = temp->next;
                       newNode->prev = temp;

                       if (temp->next != NULL){
                           temp->next->prev = newNode;}

                       temp->next = newNode;
                       return;
                }

      }
}

// delete First Node 

void deleteAtFirst(){

        if(head==NULL){
                printf("=> List Is Already Empty .");
                return;
        }
        else{
                struct Node* temp = head;
                head=temp->next;
               if(head != NULL) {
                head->prev=NULL;
               }
                free(temp);
                return;
        }
}

void deleteAtLast(){
         struct Node* temp = head;
         if(head==NULL)
         {
                printf("=> List Is Already Empty .");
                return;
         }
         if (temp->next == NULL) 
         {
               free(temp);
              head = NULL;
              return;
         }
         else{
          
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                 }   
                 temp->prev->next=NULL;
                 free(temp);
                 return;
         }

}
void deleteAtPosition(){
 
          int pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    if(head==NULL){
        printf("LIst is Empty ");
        return;
    }
    if (pos < 1 || head == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node* temp = head;

    if (pos == 1) {
       deleteAtFirst();
        return;
    }
     else{
        for(int i=1;i<pos-1&&temp->next!=NULL;i++){
                temp=temp->next;
        }

        if(temp==NULL){
                deleteAtLast();
        }else{
             struct Node* del = temp->next;
            temp->next = del->next;
            if (del->next != NULL) {
                del->next->prev = temp;
                 
        }
        free(del);
     }
         
}
}
// Reverse doubly linked list
void reverseList() {
    struct Node* current = head;
    struct Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;
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

// Display list backward
void displayBackward() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("List (backward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Count nodes
void countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total nodes: %d\n", count);
}

int main(){
    int choice;
    do {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete First Node\n");
        printf("5. Delete Last Node\n");
        printf("6. Delete at Position\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Count Nodes\n");
        printf("10. Reverse List\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtFirst(); break;
            case 2: insertAtEnd(); break;
            case 3:  insertAtPosition(); break;
            case 4: deleteAtFirst(); break;
            case 5: deleteAtLast(); break;
            case 6:deleteAtPosition();break;
            case 7: displayForward(); break;
            case 8: displayBackward(); break;
            case 9: countNodes(); break;
            case 10: reverseList(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 0);
    return 0;
}

