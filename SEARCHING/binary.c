#include <stdio.h>

// Recursive  Binary Search
int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1;  
    }

    int mid = (low + high) / 2;

    if (arr[mid] == key) {
        return mid;   
    } 
    else if (key < arr[mid]) {
        return binarySearch(arr, low, mid - 1, key);  
    } 
    else {
        return binarySearch(arr, mid + 1, high, key);
    }
}
// Without Recursion Binary Search

int binarySearchIterative(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (key < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
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
// recursive
    result = binarySearch(arr, 0, size - 1, key);

    if (result != -1) {
        printf("(Recursive) Element %d found at index %d\n", key, result);
    } else {
        printf("(Recursive) Element %d not found in the array\n", key);
    }
    // iterative
    result = binarySearchIterative(arr, size, key);

    if (result != -1) {
        printf("(Iterative) Element %d found at index %d\n", key, result);
    } else {
        printf("(Iterative) Element %d not found in the array\n", key);
    }

    return 0;
}
