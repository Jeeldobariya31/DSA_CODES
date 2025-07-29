#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SIZE 100

int top=-1;
int stack[SIZE];
void push(char c) {
    if (top >= SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}


char pop() {
    if (top < 0) {
        return -1; 
    }
    return stack[top--];
}

void processString(char s[]){
         int len = strlen(s);
         char temp;
         int flag=0;
         int i;
         
            
        
    for ( i = 0; i < len; i++) 
    {
        if (s[i] == '['||s[i] == '('||s[i] == '{') 
        {
            push(s[i]);
        } 
        else if(s[i] == ']') {
           temp= pop(); 
           if(temp!='['){
                flag=1;
           }
        }
        else if(s[i] == ')') {
           temp= pop(); 
           if(temp!='('){
                flag=1;
           }
        }
        else if(s[i] == '}') {
           temp= pop(); 
           if(temp!='{'){
                flag=1;
           }
        }
        else{
            flag=1;
        }
        
    }
    if(flag==1){
        printf("\n0\n");
    }
   else{
        printf("\n1\n");
    }

}

int main() {
    char s[SIZE];

    printf("Enter the input string: ");
    scanf("%s", s);

    processString(s);

    return 0;
}
