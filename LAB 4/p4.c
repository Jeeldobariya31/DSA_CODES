#include <stdio.h>

int main() {
    int i, n, ind, j, k;
    
    printf("Enter array size: ");
    scanf("%d", &n);
    
    int a[100];
    printf("Enter element in ascanding order :\n");
    for (i = 0; i < n; i++) {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &a[i]);
    }
    
    printf("Enter index where you want to delete the value: ");
    scanf("%d", &ind);
    
   

    for (j = ind; j <n; j++) {
        a[j] = a[j+1];
    }
    
    printf("Printing array *****\n");
    for (k = 0; k < n -1; k++) {
        printf("%d,", a[k]);
    }

    return 0;
}
