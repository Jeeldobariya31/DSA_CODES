#include <stdio.h>

int main() {
    int indofa, indofb, i, k = 0, n, m;

    printf("Enter first array size: ");
    scanf("%d", &indofa);
    int a[indofa];
    printf("Enter %d elements of first array:\n", indofa);
    for (i = 0; i < indofa; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter second array size: ");
    scanf("%d", &indofb);
    int b[indofb];
    printf("Enter %d elements of second array:\n", indofb);
    for (i = 0; i < indofb; i++) {
        scanf("%d", &b[i]);  
    }

    // Merging arrays
    int c[indofa + indofb];
    for (n = 0; n < indofa; n++) {
        c[k++] = a[n];
    }
    for (m = 0; m < indofb; m++) { 
        c[k++] = b[m];
    }

    printf("Merged array:\n");
    for (i = 0; i < indofa + indofb; i++) {
        printf("%d, ", c[i]);
    }

    return 0;
}
