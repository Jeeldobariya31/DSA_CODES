// #include<stdio.h>
// int main(){
// printf("Enter Number");
// int pow;
// int num;
// int i,ans=1;
// printf("Enter number & power in order :  ");
// scanf("%d",&num);
// scanf("%d",&pow);

// for(i=1;i<=pow;i++){
// ans=num*ans;
// }
//  printf("Your ans is: %d",ans);

// }

//******* Method 2 Recursive function

#include<stdio.h>
int Power(int num,int powe){
        int ans=1;
        if(powe==0){
                return 1;
        }
        else{
                return num*Power(num,powe-1);
        }
}
int main(){
        printf("Enter Number");
int pow;
int num;
printf("Enter number & power in order :  ");
scanf("%d",&num);
scanf("%d",&pow);
int ans=Power(num,pow);
printf("Your ans is: %d",ans);
}