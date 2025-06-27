#include<stdio.h>
int main(){
        int s;
        printf("Enter Size of An Array :");
        scanf("%d",&s);
        
        int a[s],i;
        int sum=0,j;

        printf("******Scaning of Array :****\n");
        for(i=0;i<s;i++){
                printf("Enter Element for index %d :",i);
                scanf("%d",&a[i]);
        
        }
          printf("******Scaning of limits for sum in order to m&n :****\n");
          int m,n;
          printf("Enter starting value :");{
                scanf("%d",&m);
                 printf("Enter ending value :");{
                scanf("%d",&n);
                if(m>=s||n>=s||(m>=s&&n>=s)){
                        printf("** Enter valied index of array **");
                }
                else if (m>n){
                      printf("** Enter valied index because here starting index is gretaer than ending index **");   
                }
                else{
                        
                        for(j=m;j<=n;j++){
                           sum=sum+a[j];
                        }
                }
          }
        }

         printf("sum is : %d",sum);
        return 0;

}