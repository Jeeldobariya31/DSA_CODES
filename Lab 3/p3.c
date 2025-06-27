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
        for(j=0;j<s;j++){
                sum=sum+a[j];
        }
        float avg = (sum*(1.0))/s;
        printf("Avg is : %f",avg);
        return 0;
}