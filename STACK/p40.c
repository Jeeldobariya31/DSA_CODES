#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reverse(char *str, int len) {
    int i = 0, j = len - 1;
    while(i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void processString(char *s) {
    char result[1001];
    int len = 0;

    for(int i = 0; s[i] != '\0'; i++) {
        if( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            reverse(result, len);
        }
        result[len++] = s[i];
    }

    result[len] = '\0';
    printf("%s\n", result);
}

int main() {
    char S[1001];
    printf("Enter String:");
    scanf("%s", S);
    processString(S);
    return 0;
}
