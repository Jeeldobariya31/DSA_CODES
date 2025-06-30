#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node * First=NULL;
void addAtFirst() {
    int value;
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value: ");
    scanf("%d", &value);
    new_node->data = value;
    new_node->link = First;
    First = new_node;
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


   
// Function to swap consecutive nodes
void swapConsecutiveNodes() {
    if (First == NULL ||  First->link == NULL)
        return;

    struct Node* prev = NULL;
    struct Node* current = First;
 // second node make first after swaping 
 // tharfore wi push first pointer on second position
 
    First = First->link; 

    while (current != NULL && current->link != NULL) {
        struct Node* nextNode = current->link;
        //next pair point to whose node which come after thi curent 2 nodes
        struct Node* nextPair = nextNode->link;

        // Swap current and nextNode
        nextNode->link = current;
        current->link = nextPair;

        // Link previous pair to current swapped pair
        if (prev != NULL)
            prev->link = nextNode;

        // Move prev and current forward
        prev = current;
        current = nextPair;
    }
}



int main() {
        int ch;
    do{
        printf("\n---- Singly Linked List Menu ----\n");
        printf("1. Insert at Front\n");
        printf("2.Print Entered List \n");
        printf("3.To swap Consecutive Nodes In list \n");
        printf("Enter choice =>");
        scanf("%d",&ch);

         switch(ch){
                case 1:addAtFirst();
                       break;
                case 2:printList();     
                       break;
                case 3:swapConsecutiveNodes();
                       break;
                case 0:printf("EXIT>>>>") ;
                        break;
                default : printf("INVALIED CHOICE>>>>>");
                          break;                     
         }

    }while(ch!=0);
        return 0;
}
