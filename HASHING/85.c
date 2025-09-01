// Linear Probing Hashing with Full Insertion Handling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define ELEMENTS 15

int hashFunction(int x) {
    return (x % 18) + 2;  
}

void insertHash(int arr[], int value) {
    int index = hashFunction(value);
    int startIndex = index;  
    int inserted = 0;

    while (arr[index] != -1) {
        if (arr[index] == value) { // Prevent duplicate insertion
            printf("\nDuplicate found! Value %d already exists at index %d.\n", value, index);
            return;
        }

        index = (index + 1) % SIZE;
        if (index == startIndex) {
            printf("\nHash table is FULL! Could not insert %d.\n", value);
            return;
        }
    }

    arr[index] = value;
    inserted = 1;
}

int searchHash(int arr[], int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (arr[index] != -1) { 
        if (arr[index] == key) {
            return index; 
        }

        index = (index + 1) % SIZE;
        if (index == startIndex) {
            break;
        }
    }

    return -1; 
}

int main() {
    int arr[SIZE];
    int i, num, key;

    for (i = 0; i < SIZE; i++) {
        arr[i] = -1;
    }

    srand(time(0));

    printf("Generated values:\n");
    for (i = 0; i < ELEMENTS; i++) {
        num = (rand() % 900000) + 100000; 
        printf("%d ", num);
        insertHash(arr, num);
    }

    printf("\n\nFinal Hash Table:\n");
    for (i = 0; i < SIZE; i++) {
        if (arr[i] == -1)
            printf("[%2d] : ---\n", i);
        else
            printf("[%2d] : %d\n", i, arr[i]);
    }

    // Searching
    printf("\nEnter a key to search: ");
    scanf("%d", &key);

    int result = searchHash(arr, key);
    if (result != -1)
        printf("Key %d found at index %d.\n", key, result);
    else
        printf("Key %d not found in the hash table.\n", key);

    return 0;
}
