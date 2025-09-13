#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKETS 5
#define BLOCK_SIZE 4

struct Record {
    char name[30];
    int age;
    float salary;
};

struct Block {
    struct Record records[BLOCK_SIZE];
    int count;
    struct Block* next;
    struct Block* prev;
};

struct Block* directory[BUCKETS] = {NULL};

int hashFunction(int age) {
    return age % BUCKETS;
}

void insertRecord(char name[], int age, float salary) {
    int index = hashFunction(age);
    struct Block* head = directory[index];

    struct Record newRecord;
    strcpy(newRecord.name, name);
    newRecord.age = age;
    newRecord.salary = salary;

    if (head == NULL) {
        head = (struct Block*)malloc(sizeof(struct Block));
        head->records[0] = newRecord;
        head->count = 1;
        head->next = head->prev = NULL;
        directory[index] = head;
        return;
    }

    struct Block* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->count < BLOCK_SIZE) {
        temp->records[temp->count++] = newRecord;
    } else {
        struct Block* newBlock = (struct Block*)malloc(sizeof(struct Block));
        newBlock->records[0] = newRecord;
        newBlock->count = 1;
        newBlock->next = NULL;
        newBlock->prev = temp;
        temp->next = newBlock;
    }
}

void searchRecord(char name[]) {
    int found = 0;
    for (int i = 0; i < BUCKETS; i++) {
        struct Block* temp = directory[i];
        while (temp) {
            for (int j = 0; j < temp->count; j++) {
                if (strcmp(temp->records[j].name, name) == 0) {
                    printf("Found in Bucket %d: Name=%s, Age=%d, Salary=%.2f\n",
                           i, temp->records[j].name, temp->records[j].age, temp->records[j].salary);
                    found = 1;
                }
            }
            temp = temp->next;
        }
    }
    if (!found)
        printf("Record with name '%s' not found.\n", name);
}

void deleteRecord(char name[]) {
    for (int i = 0; i < BUCKETS; i++) {
        struct Block* temp = directory[i];
        while (temp) {
            for (int j = 0; j < temp->count; j++) {
                if (strcmp(temp->records[j].name, name) == 0) {
                    for (int k = j; k < temp->count - 1; k++) {
                        temp->records[k] = temp->records[k + 1];
                    }
                    temp->count--;

                    if (temp->count == 0 && temp->prev != NULL) {
                        temp->prev->next = temp->next;
                        if (temp->next)
                            temp->next->prev = temp->prev;
                        free(temp);
                    }
                    printf("Record '%s' deleted from Bucket %d\n", name, i);
                    return;
                }
            }
            temp = temp->next;
        }
    }
    printf("Record with name '%s' not found for deletion.\n", name);
}

void display() {
    printf("\n--- Hash Table ---\n");
    for (int i = 0; i < BUCKETS; i++) {
        printf("Bucket %d: ", i);
        struct Block* temp = directory[i];
        if (!temp) {
            printf("Empty\n");
            continue;
        }
        while (temp) {
            printf("[");
            for (int j = 0; j < temp->count; j++) {
                printf("{%s, %d, %.2f}%s",
                       temp->records[j].name,
                       temp->records[j].age,
                       temp->records[j].salary,
                       (j == temp->count - 1) ? "" : ", ");
            }
            printf("] -> ");
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, age;
    float salary;
    char name[30];

    do {
        printf("\n--- Hashing with Buckets ---\n");
        printf("1. Insert Record\n");
        printf("2. Search Record\n");
        printf("3. Delete Record\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf(" %[^\n]s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                printf("Enter Salary: ");
                scanf("%f", &salary);
                insertRecord(name, age, salary);
                break;

            case 2:
                printf("Enter Name to Search: ");
                scanf(" %[^\n]s", name);
                searchRecord(name);
                break;

            case 3:
                printf("Enter Name to Delete: ");
                scanf(" %[^\n]s", name);
                deleteRecord(name);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
