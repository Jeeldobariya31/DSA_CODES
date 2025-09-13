// Quadratic Probing Hashing with User Input
#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define ELEMENTS 15

int hashFunction(int x) {
    return (x % 18) + 2;  
}

void insertHash(int arr[], int value) {
    int hash = hashFunction(value);
    int index = hash;
    int i = 0;

    while (arr[index] != -1) {
        if (arr[index] == value) { 
            printf("\nDuplicate found! Value %d already exists at index %d.\n", value, index);
            return;
        }

        i++;
        if (i >= SIZE) { 
            printf("\nHash table is FULL! Could not insert %d.\n", value);
            return;
        }

        index = (hash + i * i) % SIZE;  
    }

    arr[index] = value;
}

int searchHash(int arr[], int key) {
    int hash = hashFunction(key);
    int index = hash;
    int i = 0;

    while (arr[index] != -1) {
        if (arr[index] == key) {
            return index; 
        }

        i++;
        if (i >= SIZE) { 
            break;
        }

        index = (hash + i * i) % SIZE;  
    }

    return -1; 

int main() {
    int arr[SIZE];
    int i, num, key;

    // Initialize table with -1
    for (i = 0; i < SIZE; i++) {
        arr[i] = -1;
    }

    printf("Enter %d numbers to insert into the hash table:\n", ELEMENTS);
    for (i = 0; i < ELEMENTS; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);
        insertHash(arr, num);
    }
      // printing
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
