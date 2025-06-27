#include<stdio.h>
#include<stdlib.h>

int main(){
      int n,i;
      printf(" => How Many NUber Do You Entered :");
      scanf("%d",&n);
        int *ptr= (int*)malloc(n*sizeof(int));

        printf("\n**************** _ Scanning array _**************\n");
        for(i=0;i<n;i++){
                printf("Enter %d element :",(i+1));
                scanf("%d",ptr+i);
        }
         printf("\n****** _ Scanning of array compaleted succesfully _******\n");
         printf("\n**************** _ calculating sum ..... _**************\n");
           int sum=0;
         for(i=0;i<n;i++){
                sum=sum + *(ptr+i);
         }
         printf("=> your sum is : %d\n",sum);
         free(ptr);
         printf(" => Your memory is free ");

}