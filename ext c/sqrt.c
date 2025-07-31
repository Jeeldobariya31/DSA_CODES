#include <stdio.h>

int findSqrt(int n) {
    int i = 1;
    while (i * i <= n) {
        i++;
    }
    return i - 1;  
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Square root of negative number is not real.\n");
    } else {
        int result = findSqrt(number);
        printf("Square root  of %d is: %d\n", number, result);
    }

    return 0;
}
