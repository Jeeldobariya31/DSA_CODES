#include <stdio.h>
#include <math.h> // for pow()

void main() {
    int n1, n2;
    printf("Enter number-1 = ");
    scanf("%d", &n1);
    printf("Enter number-2 = ");
    scanf("%d", &n2);

    for (int i = n1; i <= n2; i++) {
        int temp = i, count = 0, sum = 0;

        // Count the number of digits
        while (temp != 0) {
            temp /= 10;
            count++;
        }
     // Armstrong number calculation
        temp = i;
        while (temp != 0) {
            int r = temp % 10;
            sum += pow(r, count); 
            temp /= 10;
        }

        if (i == sum) {
            printf("%d, ", i); // Armstrong number
        }
    }
}
