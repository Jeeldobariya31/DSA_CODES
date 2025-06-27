#include<stdio.h>
int main()
{
        int num1,num2,i,z,count=0;
        printf("enter number-1 :");
        scanf("%d",&num1);
         printf("enter number-2 :");
        scanf("%d",&num2);
        if(num2>num1){
                for(z=num1;z<=num2;z++){
                        int count=0;
           for(i=1;i<=z;i++){
                if(z%i==0)      
                {
                        count ++;
                }
        }
        if(count==2){
                printf("%d ,",z);
        }
                }
        }
        
        else{
                int count=0;
                for(z=num2;z<=num1;z++){
                         int count=0;
           for(i=1;i<=z;i++){
                if(z%i==0)      
                {
                        count ++;
                }
        }
        if(count==2){
                printf("%d ,",z);
        }
        }
}
 if(num1==num2){
        printf("give different number's");
 }
       
        return 0;
}