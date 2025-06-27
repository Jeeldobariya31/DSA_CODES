#include <stdio.h>

int main() {
    int i, n, ind, ele, j, k;
    
    printf("Enter array size: ");
    scanf("%d", &n);
    
    int a[100];
    
    for (i = 0; i < n; i++) {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &a[i]);
    }
    
    printf("Enter index where you want to insert the value: ");
    scanf("%d", &ind);
    
    printf("Enter the element you want to insert: ");
    scanf("%d", &ele);
    

    for (j = n; j > ind; j--) {
        a[j] = a[j - 1];
    }
    

    a[ind] = ele;
    
    printf("Printing array *****\n");
    for (k = 0; k < n + 1; k++) {
        printf("%d,", a[k]);
    }

    return 0;
}
