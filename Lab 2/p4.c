#include<stdio.h>
int main()
{
        int num,i;
        printf("enter number for find factor:");
        scanf("%d",&num);
        for(i=1;i<=num;i++){
                if(num%i==0)      
                {
                        printf(" %d,",i);
                }
        }
        return 0;
}