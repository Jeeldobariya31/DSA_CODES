#include<stdio.h>
int main(){
        int s;
        printf("Enter Size of An Array :");
        scanf("%d",&s);
        
        int a[s],b[s],i,j,m,n,k;
        int flag=0;
      

        printf("******Scaning of Array :****\n");
        for(i=0;i<s;i++){
                printf("Enter Element for index %d :",i);
                scanf("%d",&a[i]);
        
        }
         printf("******Scaning of m(number which replace by n) & n:****\n");
         printf("Enter N :");
         scanf("%d",&n);
         printf("Enter M :");
         scanf("%d",&m);

        for(j=0;j<s;j++){
            if(a[j]==m){
                a[j]=n;
                flag=1;
            }
        }
        if(flag==0){
                printf("*** Array don't have any changes ***\n");
                 printf(" $$$$ Your Process is Complated ----\n");
        }
        else{
                printf("*** Array  have been changed Sucsessfully ***\n");
                printf(" ---- Printing Array ----\n");
                for(k=0;k<s;k++){
                        printf("%d ,",a[k]);
                }
                 printf("\n $$$$ Your Process is Complated ----\n");

        }


        return 0;
}