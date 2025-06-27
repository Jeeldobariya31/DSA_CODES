#include<stdio.h>
int main(){
        int i;
        int j;
        int m=1;
        for(i=1;i<=5;i++){
             for(j=1;j<=i;j++){
                printf("%d ",m);
                if(m==1){
                        m=0;
                }
                else{
                        m=1;
                }
             }
             printf("\n");
        }
        return 0;
}