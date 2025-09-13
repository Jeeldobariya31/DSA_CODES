#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function using first element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  
    int i = low + 1;       
    int j = high;

    while (1) {
        // Find element greater than pivot from left
        while (i <= j && arr[i] <= pivot)
            i++;
        // Find element smaller than pivot from right
        while (arr[j] > pivot)
            j--;

        if (i < j) {
            swap(&arr[i], &arr[j]);
        } else {
            break;
        }
    }

    // Place pivot at correct position
    swap(&arr[low], &arr[j]);
    return j;  // pivot index
}

//  Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nOriginal array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("\nSorted array: ");
    printArray(arr, n);

    return 0;
}
