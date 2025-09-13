#include <stdio.h>
#include <stdlib.h>

// Merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    // Copy data into temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];   // left part
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j]; // right part

    
    int i = 0;      
    int j = 0;      
    int k = left;   

    // Step 5: Compare elements 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {      
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++; 
}

    //  Copy remaining elements of L[] 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    //  Copy remaining elements of R[] 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


// merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

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

    mergeSort(arr, 0, n - 1);

    printf("\nSorted array: ");
    printArray(arr, n);

    return 0;
}
