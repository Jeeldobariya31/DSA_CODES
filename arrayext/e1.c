#include<stdio.h>
int main(){

        printf("=>>> plese enter different num ");
        int size,tar;
        printf("enter size :");
        scanf("%d",&size);
        int a[size];
        int o[2];
        printf("-_-_-_-_scaning array ________\n");
        for(int i=0;i<size;i++){
                printf("Enter %d th element ",(i+1));
                scanf("%d",&a[i]);
        }
        printf("Enter Targate : ");
        scanf("%d",&tar);
        int f=0;
        for(int j=0;j<size;j++){
                for(int k=0;k<size;k++){
                      if(j!=k){
                        if(a[j]+a[k]==tar){
                                if(k>j){
                                o[0]=k;
                                o[1]=j;}
                                else{
                                o[0]=j;
                                o[1]=k;   
                                }
                                break;
                                f==1;
                        }
                      }
                }
                if(f==1){
                        break;
                }
        }

        printf("Your ans is : [%d,%d]",o[0],o[1]);
}