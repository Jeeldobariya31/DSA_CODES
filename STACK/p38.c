#include <stdio.h>
#include <string.h>

#define SIZE 100

int top = -1;
char stack[SIZE];


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

//main logic
void processString(char s[]) {
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (s[i] != '*') {
            push(s[i]);
        } else {
            pop(); 
        }
    }


    printf("Output: ");
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
    printf("\n");
}

int main() {
    char s[SIZE];

    printf("Enter the input string: ");
    scanf("%s", s);

    processString(s);

    return 0;
}
