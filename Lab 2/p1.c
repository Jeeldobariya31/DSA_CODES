// #include<stdio.h>

// int Fact(int n){
//         if (n==0||n==1){
//                 return 1;
//         }
//         else{
//                 return n*Fact(n-1);
//         }
// }
// int main(){
//         printf("enter number to fond factorial ");
//         int n;
//         scanf("%d",&n);
//         int ans= Fact(n);
//         printf("Your ans is: %d",ans);

// }

// method 2 simple method 

#include<stdio.h>
int main(){
     printf("enter number to fond factorial ");
        int n;
         scanf("%d",&n);
         int i,ans=1;
         for(i=1;i<=n;i++){
           ans=ans*i;
         }
         printf("Your ans is: %d",ans);
}