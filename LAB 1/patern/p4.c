#include<stdio.h>
int main(){
        int i;
        int j;
        for(i=1;i<=5;i++){
             for(j=1;j<=i;j++){
                printf("%d ",i);
             }
             printf("\n");
        }
        return 0;
}