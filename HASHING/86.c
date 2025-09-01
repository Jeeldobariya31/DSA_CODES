// implement dictionary using hash table
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20   


struct DictItem {
    char key[50];
    char value[50];
};


struct DictItem* hashTable[SIZE];

// Hash function
int hashFunction(char *key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];  
    }
    return sum % SIZE;
}

void insert(char *key, char *value) {
    int index = hashFunction(key);


    while (hashTable[index] != NULL) {
        if (strcmp(hashTable[index]->key, key) == 0) {
            // Key already exists  update value
            strcpy(hashTable[index]->value, value);
            return;
        }
        index = (index + 1) % SIZE;
    }

    // Create new item
    struct DictItem* newItem = (struct DictItem*)malloc(sizeof(struct DictItem));
    strcpy(newItem->key, key);
    strcpy(newItem->value, value);

    hashTable[index] = newItem;
}

// Search 
char* search(char *key) {
    int index = hashFunction(key);

    while (hashTable[index] != NULL) {
        if (strcmp(hashTable[index]->key, key) == 0) {
            return hashTable[index]->value;
        }
        index = (index + 1) % SIZE;
    }
    return NULL; 
}

// Delete key-value pair
void delete(char *key) {
    int index = hashFunction(key);

    while (hashTable[index] != NULL) {
        if (strcmp(hashTable[index]->key, key) == 0) {
            free(hashTable[index]);
            hashTable[index] = NULL;
            printf("Deleted key: %s\n", key);
            return;
        }
        index = (index + 1) % SIZE;
    }
    printf("Key %s not found!\n", key);
}

// Display 
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != NULL) {
            printf("[%2d] Key: %s  | Value: %s\n", i, hashTable[i]->key, hashTable[i]->value);
        } else {
            printf("[%2d] ---\n", i);
        }
    }
}

int main() {
    // Initialize hash table
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }

    insert("name", "Jeel");
    insert("age", "21");
    insert("city", "Rajkot");
    insert("course", "B.Tech");

    display();

    char *val = search("city");
    if (val != NULL)
        printf("\nSearch result -> city: %s\n", val);
    else
        printf("\nKey not found!\n");

    delete("age");
    display();

    return 0;
}
