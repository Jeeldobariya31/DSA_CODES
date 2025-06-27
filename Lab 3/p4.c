#include<stdio.h>
int main(){
        int s;
        printf("Enter Size of An Array :");
        scanf("%d",&s);
        
        int a[s],i;
        int sum=0,j;

        printf("******Scaning of Array :****\n");
        for(i=0;i<s;i++){
                printf("Enter Element for index %d :",i);
                scanf("%d",&a[i]);
        
        }
        int min=a[0];
        int max=a[0];
        for(j=0;j<s;j++){
               if(a[j]<min){
                min=a[j];
               }
                if(a[j]>max){
                max=a[j];
               }
        }
        printf("***Printing Result***\n");
        printf("Minimum is %d\n",min);
         printf("Maximum is %d\n",max);
        return 0;
}