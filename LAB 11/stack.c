// STACK IMLIMENTATION 😎
#include<stdio.h>
#include<stdlib.h>

struct Stack{
        int data ;
        struct Stack * link;
};

struct Stack * Top =NULL;

void push(){
 int value;
    struct Stack* new_Stack = (struct Stack*)malloc(sizeof(struct Stack));
    printf("Enter value: ");
    scanf("%d", &value);
    new_Stack->data = value;
    new_Stack->link = NULL;

    if (Top == NULL) {
        Top = new_Stack;
    } else {
         new_Stack->link = Top;
         Top = new_Stack;
    }
}
void pop(){
 if (Top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Stack* temp = Top;
    Top = Top->link;      
     printf("Your pop element is : %d\n",temp->data);
    free(temp);
}
void  top(){
        int tops;
        tops=Top->data;
       printf("Your top element is : %d\n",tops);
}
void print(){
        struct Stack* temp = Top;
    if (temp == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Current Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}
int main(){
        int choice;
        do{
               
                printf(" => Enter Choice 1 For push . \n");
                printf(" => Enter Choice 2 For pop . \n");
                printf(" => Enter Choice 3 For top . \n");
                printf(" => Enter Choice 4 For Pint Stack . \n");
                 printf(" => Enter Choice 0 For Exit . \n");
                  printf("Enter Choice Do you Enter For Stack :");
                scanf("%d",&choice);
                

                switch(choice){
                        case 1: push();
                                 break;
                        case 2: pop();
                                break;
                        case 3: top();
                                break;
                        case 4: print();
                                break;  
                        case 0: printf("EXIT .");
                                break;              
                        default : printf("Invalied Choice :\n");
                                  break;     
                }
        }
        while(choice!=0);
}