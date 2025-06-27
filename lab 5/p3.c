#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void sortString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void toLowerCase(char *str) {
     int len = strlen(str);
    for (int i = 0; i<len; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    int nameCount;
    printf("How many names you want to enter: ");
    scanf("%d", &nameCount);

    char a[nameCount][100];
    char input[100];
    char compare[100];

    printf("****** Scanning Names ******\n");
    for (int i = 0; i < nameCount; i++) {
        printf("Enter %d-th name: ", i + 1);
        scanf("%s", a[i]);
    }

    
    int num = rand() % nameCount;
    strcpy(compare, a[num]);
    printf("Random Word is: %s\n", compare);

    
    printf("Enter your word: ");
    scanf("%s", input);

    
    toLowerCase(input);
    toLowerCase(compare);

    
    sortString(input);
    sortString(compare);

    
    if (strcmp(input, compare) == 0) {
        printf("=> Given words are anagrams.\n");
    } else {
        printf("=> Given words are not anagrams.\n");
    }

    return 0;
}
