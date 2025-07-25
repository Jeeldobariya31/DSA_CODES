#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

int main(){
struct node *First=NULL;


struct node *newNode = (struct node *) malloc (sizeof (struct node));

printf("Enter data");
scanf("%d" , &newNode -> data);
newNode->link = NULL;

printf("\nPrinting detailes :*********");
printf("info:%d \n"newNode->data);
printf("link:%d \n"newNode->link);

}