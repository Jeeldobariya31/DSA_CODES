#include<stdio.h>
int main(){
        printf("enter charecter :");
        char c;
        scanf("%c",&c);
        if(c=='i'||c=='o'||c=='u'||c=='e'||c=='a'||c=='I'||c=='O'||c=='U'||c=='E'||c=='A')
        {
 printf("ch %c is vowel",c);
        }
        else{
               printf("ch %c is constant",c);
        }
       return 0;
}