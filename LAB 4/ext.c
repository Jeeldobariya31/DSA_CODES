#include<stdio.h>
int main(){
                 
        int i,a[100],n;
        printf("Enter how many element do you insert (maximum 100)");
        scanf("%d",&n);
        for(i=0;i<n;i++){
              printf("Enter %d element :",(i+1));
              scanf("%d",&a[i]);
        }
        printf("Printing array *****\n");
        for(i=0;i<n;i++){
              printf("%d,",a[i]);
        }
         

        return 0;
}