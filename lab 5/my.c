// anagram words code
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
        int name,i,j=0,k=0;
        printf("How many name you has been enter :");
        scanf("%d",&name);
        
        char a[name][100];
        char input[100];
        char compare[100];
         char temp[100];
         char temp2[100];
       
      

        printf("******Scaning of Array of name :****\n");
        for(i=0;i<name;i++){
                printf("Enter %d th name :",i+1);
                scanf("%s",&a[i]);
        
        }
         int num = rand() % name ;
         for(i=0;i<name;i++){
                if(i==num){
                        printf("Random Word is: %s \n",a[i]);
                        compare=a[i];
                }
         }
         printf("Enter Your word's :");
         scanf("%s",input);
         input=input.lowerCase();
         compare=compare.lowerCase();
       
           for(i=0;i<input.length;i++)
           {
                if(input[i]=="\0"){
                        break;
                }
                else if(input[i]<=input[i+1]){
                       temp[j]=input[i];
                       j++;
                }
           }
           for(i=0;i<compare.length;i++)
           {
                if(compare[i]=="\0"){
                        break;
                }
                else if(compare[i]<=compare[i+1]){
                       temp2[k]=compare[i];
                       k++;
                }
           }
         if(temp1.compareTo(temp2)==0){
                printf(" => Given Words is anagram ");
         }
         else{
                printf(" => Given Words is not anagram ");
         }

        return 0;
}