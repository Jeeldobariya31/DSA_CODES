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
         printf("\n**************** _ shorting array _**************\n");

 for(i=0; i<n; i++)
    {
        for(j=0; j<n-1; j++) {
            if(*(ptr+i)<*(ptr+j))
            {
                temp = *(ptr+i);
                *(ptr+i)= *(ptr+j);
                *(ptr+j) = temp;
            }
        }
    }
         printf("\n**************** _ printing shorted array _**************\n");

         for(i=0;i<n;i++){
                printf("Your %d element is : %d \n",(i+1),*(ptr+i));
         }
         printf("\n****** _ printing of array compaleted succesfully _******\n");
         free(ptr);
         printf("Your memory is free ");

}