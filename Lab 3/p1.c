#include<stdio.h>
int main(){
        int s;
        printf("Enter Size of An Array :");
        scanf("%d",&s);
        
        int a[s],i;

        printf("******Scaning of Array :****\n");
        for(i=0;i<s;i++){
                printf("Enter Element for index %d :",i);
                scanf("%d",&a[i]);
        
        }
        printf("\n");
        printf("******printing  of Array :****\n");
        for(i=0;i<s;i++){
                printf("%d ,",a[i]);
              
        
        }
        return 0;
}