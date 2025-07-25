#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[100];
    char branch[50];
    int batch_no;
};

int main() 
{
    char names[100];
    int roll;
    int b;
    char branchs[50];

     printf("\n---***_ Student Info Scaning _***---\n");

    printf("Enter name with out space : ");
    scanf("%s", names);  

    printf("Enter roll no : ");
    scanf("%d", &roll);

    printf("Enter batch : ");
    scanf("%d", &b);

    printf("Enter branch name : ");
    scanf("%s", branchs);

    struct Student* stu1 = (struct Student*) malloc(sizeof(struct Student));

   
    strcpy(stu1->name, names);
    strcpy(stu1->branch, branchs);
    stu1->roll_no = roll;
    stu1->batch_no = b;

    printf("\n---***_ Student Info printing _***---\n");
    printf("Name       : %s\n", stu1->name);
    printf("Roll No    : %d\n", stu1->roll_no);
    printf("Branch     : %s\n", stu1->branch);
    printf("Batch No   : %d\n", stu1->batch_no);

   
    free(stu1);
    printf("=> Your memory is free .");

    return 0;
}
