#include<stdio.h>
int main()
{
        int num,i,count=0;
        printf("enter number :");
        scanf("%d",&num);
        for(i=1;i<=num;i++){
                if(num%i==0)      
                {
                        count ++;
                }
        }
        if(count==2){
                printf("Give number is PRIME");
        }
        else{
               printf("Give number is NOT PRIME");  
        }
        return 0;
}