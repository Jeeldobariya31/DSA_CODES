#include<stdio.h>
#include<stdlib.h>

int main(){
      int n,i,j,temp;
      printf("Enter size of array :");
      scanf("%d",&n);
        int *ptr= (int*)malloc(n*sizeof(int));

        printf("\n**************** _ Scanning array _**************\n");
        for(i=0;i<n;i++){
                printf("Enter %d element :",(i+1));
                scanf("%d",ptr+i);
        }
         printf("\n****** _ Scanning of array compaleted succesfully _******\n");
         int min=*ptr;
        int max=*ptr;
        for(j=0;j<n;j++){
               if(*(ptr+j)<min){
                min=*(ptr+j);
               }
                if(*(ptr+j)>max){
                max=*(ptr+j);
               }
        }
        printf("***Printing Result***\n");
        printf("Minimum is %d\n",min);
         printf("Maximum is %d\n",max);
         free(ptr);
         printf("Your memory is free ");

}