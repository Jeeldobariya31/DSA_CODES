#include<stdio.h>
int main(){
        int n;
        int i;
        int j;
        int sum=0;
        printf("enter stap no");
        scanf("%d",&n);
        for(i=1;i<=n;i++){
           for(j=1;j<=i;j++){
                sum=sum+j;
           }
        }
        printf("sum is %d",sum);
        return 0;
}