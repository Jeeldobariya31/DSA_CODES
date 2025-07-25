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
//Find GCD
int gcd(int num1,int num2)
{
    int n1=num1, n2=num2, i, gcd;
    for(i=1; i <= n1 && i <= n2; ++i)
    {
        if(n1%i==0 && n2%i==0)
            gcd = i;
    }
    return gcd;
}
// add gcd node
void addgcd(){
   struct Node * curr=First;
   struct Node * next=curr->link;
   while(next !=NULL){
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data=gcd(curr->data,next->data);
        curr->link=new_node;
        new_node->link=next;
        curr=next;
        next=curr->link;
   }
}
int main() {
        int ch;
    do{
        printf("\n---- Singly Linked List Menu ----\n");
        printf("1. Insert at Front\n");
        printf("2.Print Entered List \n");
        printf("3.convert gcd added list \n");
        printf("Enter choice =>");
        scanf("%d",&ch);

         switch(ch){
                case 1:addAtFirst();
                       break;
                case 2:printList();     
                       break;
                case 3:addgcd();
                       break;
                case 0:printf("EXIT>>>>") ;
                        break;
                default : printf("INVALIED CHOICE>>>>>");
                          break;                     
         }

    }while(ch!=0);
        return 0;
}
