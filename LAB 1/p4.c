#include<stdio.h>
int main(){
        int a;
        int b;
        int c;
        printf("enter number a :");
          scanf("%d",&a);
          printf("enter number b :");
          scanf("%d",&b);
          printf("enter number c :");
          scanf("%d",&c);
        
          if(a>b){
                if(a>c){
                        printf("num %d is largest",a);
                }
                else{
                             printf("num %d is largest",c);
                }
          }
          else{
               if(b>c){
                        printf("num %d is largest",b);
                }
                else{
                             printf("num %d is largest",c);
                } 
          }
      
       return 0;
}