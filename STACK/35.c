// How stack can be used to recognize strings aca, bcb, abcba, abbcbba? Write a 
//program to solve the above problem. 

#include <stdio.h>
#include <string.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch) {
    if (top >= SIZE - 1) {.
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = ch;
    }
}

char pop() {
    if (top < 0) {
        return '\0';
    } else {
        return stack[top--];
    }
}

// Special palindrome check with middle char 'c'
void isSpecialPalindrome(char str[]) {
    int i = 0;

    // Push until middle character 'c'
    while (str[i] != 'c') {
        if (str[i] == '\0') {
            printf("Invalid string. 'c' not found.\n");
            return;
        }
        push(str[i]);
        i++;
    }

    i++; // Skip 'c'

    
    while (str[i] != '\0') {
        char temp = pop();
        if (temp != str[i]) {
            printf("Invalid string. Not a palindrome around 'c'.\n");
            return;
        }
        i++;
    }

    if (top == -1) {
        printf("Valid palindrome ......\n");
    } else {
        printf("Invalid string. Stack not empty.\n");
    }
}

int main() {
    char input[SIZE];
    printf("Enter a string: ");
    scanf("%s", input);
    isSpecialPalindrome(input);
    return 0;
}
