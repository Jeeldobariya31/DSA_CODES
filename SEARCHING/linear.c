#include <stdio.h>

// Recursive function for linear search
int linearSearch(int arr[], int size, int key, int index) {

    if (index == size) {
        return -1;
    }
    if (arr[index] == key) {
        return index;
    }

    return linearSearch(arr, size, key, index + 1);
}

int main() {
     int size;
    printf("Enter number of elements: ");
    scanf("%d", &size);

    int arr[size];   

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    int key, result;

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = linearSearch(arr, size, key, 0);

    if (result != -1) {
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array\n", key);
    }

    return 0;
}
