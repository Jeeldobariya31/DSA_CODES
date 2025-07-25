#include <stdio.h>
#include <stdlib.h>
int count=0;
//basics 
struct Node {
    int data;
    struct Node* link;
};
//temp pointer
struct Node* FIRST = NULL;
struct Node* LAST = NULL;
struct Node* LIST1 = NULL;
struct Node* LIST2 = NULL;



// Insert at front
void insertAtFront() {
    struct Node* NEW = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &NEW->data);
    NEW->link = NULL;

    if (FIRST == NULL) {
        NEW->link = NEW;
        FIRST = LAST = NEW;
        count ++;
    } else {
        NEW->link = FIRST;
        LAST->link = NEW;
        FIRST = NEW;
        count ++;
    }
}
//display
void display( struct Node* HEAD){
    if (HEAD == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = HEAD;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->link;
    } while (temp != HEAD);
    printf("HEAD\n");
}
void split() {
    if (FIRST == NULL) {
        printf("List is empty.\n");
        return;
    }

    int pos = count / 2;
    struct Node* temp = FIRST;
    int i = 1;

    LIST1 = FIRST;

    // Traverse to the last node of first half
    while (i < pos) {
        temp = temp->link;
        i++;
    }

    LIST2 = temp->link;  
    temp->link = LIST1;  

    struct Node* temp2 = LIST2;

    
    while (temp2->link != FIRST) {
        temp2 = temp2->link;
    }

    temp2->link = LIST2; 

    printf("List split into two halves.\n");
}

int main(){
        int choice;
        do{
             printf("=> 1.For Insert Element At First \n");
             printf("=> 2.For Display Original List \n");
             printf("=> 3.For Split List\n");
             printf("=> 4.For Display FIRST HALF PART OF List \n");
             printf("=> 5.For Display SECOND HALF PART OF List \n");
             printf("=> 0.For EXIT \n");
             printf("=>Enter choice :");
             scanf("%d",&choice);
             switch (choice) {
            case 1: insertAtFront(); break;
            case 2: display(FIRST); break;
            case 3: split();break;
            case 4: display(LIST1); break;
            case 5: display(LIST2); break;
            case 0: printf("Exiting program...\n"); break;
            default: printf("Invalid choice!\n");break;
        };
        }while(choice!=0);
        return 0;
}