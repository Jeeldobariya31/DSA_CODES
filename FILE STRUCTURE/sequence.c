#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct data {
    char name[50];
    int age;  
    double salary;  
};

struct block {
    int noofdata;
    int index;
    struct block *next;
    struct block *prev;
    struct data records[5];
};

struct sequence {
    struct block *head; 
    struct block *tail; 
    int size;
};


void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

struct block* createBlock(int index) {
    struct block *newBlock = (struct block*)malloc(sizeof(struct block));
    newBlock->index = index;
    newBlock->noofdata = 0;
    newBlock->next = NULL;
    newBlock->prev = NULL;
    return newBlock;
}

void initSequence(struct sequence *seq) {
    seq->head = NULL;
    seq->tail = NULL;
    seq->size = 0;
}

void insertRecord(struct sequence *seq, char name[], int age, double salary) {
    if (seq->head == NULL) {
        seq->head = createBlock(0);
        seq->tail = seq->head;
        seq->size = 1;
    }

    struct block *current = seq->tail;

    if (current->noofdata == 5) {
        struct block *newBlock = createBlock(seq->size);
        current->next = newBlock;
        newBlock->prev = current;
        seq->tail = newBlock;
        seq->size++;
        current = newBlock;
    }

    strcpy(current->records[current->noofdata].name, name);
    current->records[current->noofdata].age = age;
    current->records[current->noofdata].salary = salary;
    current->noofdata++;
}

void displaySequence(struct sequence *seq) {
    printf("\n");
    if (seq->head == NULL) {
        printf("Sequence is empty!\n");
        return;
    }

    struct block *temp = seq->head;
    printf("--- Sequence File Records ---\n");
    while (temp != NULL) {
        printf("Block Index: %d (Records: %d)\n", temp->index, temp->noofdata);
        for (int i = 0; i < temp->noofdata; i++) {
            printf("  [%d] Name: %s, Age: %d, Salary: %.2lf\n",
                   i + 1, temp->records[i].name,
                   temp->records[i].age,
                   temp->records[i].salary);
        }
        temp = temp->next;
    }
}

void searchRecord(struct sequence *seq, char name[]) {
    char searchName[50];
    strcpy(searchName, name);
    toLowerCase(searchName);

    struct block *temp = seq->head;
    int found = 0;

    while (temp != NULL) {
        for (int i = 0; i < temp->noofdata; i++) {
            char recordName[50];
            strcpy(recordName, temp->records[i].name);
            toLowerCase(recordName);

            if (strcmp(recordName, searchName) == 0) {
                printf("Record Found: Name: %s, Age: %d, Salary: %.2lf\n",
                       temp->records[i].name,
                       temp->records[i].age,
                       temp->records[i].salary);
                found = 1;
                break;
            }
        }
        if (found) break;
        temp = temp->next;
    }

    if (!found) printf("\nRecord not found!\n");
}

void deleteRecord(struct sequence *seq, char name[]) {
    char searchName[50];
    strcpy(searchName, name);
    toLowerCase(searchName);

    struct block *temp = seq->head;

    while (temp != NULL) {
        for (int i = 0; i < temp->noofdata; i++) {
            char recordName[50];
            strcpy(recordName, temp->records[i].name);
            toLowerCase(recordName);

            if (strcmp(recordName, searchName) == 0) {
                printf("\nRecord '%s' found in Block %d. Deleting...\n", name, temp->index);

                struct block *current = temp;
                int pos = i;

                while (current != NULL) {
                    for (int j = pos; j < current->noofdata - 1; j++) {
                        current->records[j] = current->records[j + 1];
                    }

                    if (current->next != NULL) {
                        current->records[current->noofdata - 1] = current->next->records[0];
                        current = current->next;
                        pos = 0;
                    } else {
                        current->noofdata--;
                        break;
                    }
                }

                printf("Record '%s' deleted and all subsequent records shifted!\n", name);
                return;
            }
        }
        temp = temp->next;
    }

    printf("\nRecord not found for deletion!\n");
}

int main() {
    struct sequence seq;
    initSequence(&seq);

    int choice;
    char name[50];
    int age;
    double salary;

    do {
        printf("\n--- Sequential File Menu ---");
        printf("\n1. Insert Record");
        printf("\n2. Display All Records");
        printf("\n3. Search Record");
        printf("\n4. Delete Record");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear buffer
            continue;
        }
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Enter Age: ");
                scanf("%d", &age);
                printf("Enter Salary: ");
                scanf("%lf", &salary);
                getchar(); 
                insertRecord(&seq, name, age, salary);
                printf("\nRecord inserted successfully!\n");
                break;

            case 2:
                displaySequence(&seq);
                break;

            case 3:
                printf("Enter name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                searchRecord(&seq, name);
                break;

            case 4:
                printf("Enter name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                deleteRecord(&seq, name);
                break;

            case 5:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
