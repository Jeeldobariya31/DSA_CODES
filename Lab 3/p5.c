#include<stdio.h>
int main(){
        int s;
        printf("Enter Size of An Array :");
        scanf("%d",&s);
        
        int a[s],i,j,temp,k;
        int flag=0;
      

        printf("******Scaning of Array :****\n");
        for(i=0;i<s;i++){
                printf("Enter Element for index %d :",i);
                scanf("%d",&a[i]);
        
        }
          if(flag==0){
        for(j=0;j<s;j++){
                temp=a[j];
                for(k=j+1;k<s;k++){
                        if(temp==a[k]){
                                flag =1;
                                break;
                        }
                }
        }
        }
        if(flag==0){
                printf("*** Array don't have duplicate element ***\n");
        }
        else{
              printf("*** Array  have duplicate element ***\n");   
        }

        return 0;
}