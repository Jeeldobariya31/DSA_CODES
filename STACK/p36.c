#include <stdio.h>
#include <string.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int i) {
    if (top >= SIZE - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = i;
    }
}

void valied(char str[]){
     int i=0;
     int count=0;
     int other=0;
     int len=strlen(str);
     if(len==0){
        printf("String is null ...\n");
        return;
     }
     for(i=0;i<len;i++)
     {
        if(str[i]=='a'){
                push(1);
        }
        else if(str[i]=='b'){
              count ++;
        }
        else{
                other++;
        }
     }

     if(count==top+1){
        printf("=>valied ,no of 'a' is equal to no of 'b' .\n");
        printf("total %d other cch in string ...\n",other);
     }
     else{
        printf("=>not  valied , no of 'a' is not equal to no of 'b' .\n");
        printf("total %d other cch in string ...\n",other);
     }

}
int main() {
    char input[SIZE];
    printf("Enter a string: ");
    scanf("%s", input);
    valied(input);
    return 0;
}
