#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char phone[10];
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(char name[], char phone[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, char name[], char phone[]) {
    if (root == NULL) {
        return createNode(name, phone);
    }
    if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name, phone);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insert(root->right, name, phone);
    } else {
        printf("Contact with name '%s' already exists.\n", name);
    }
    return root;
}

// Find minimum node (for deletion)
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

// Delete from BST
struct Node* deleteNode(struct Node* root, char name[]) {
    if (root == NULL) {
        printf("Contact not found!\n");
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        root->left = deleteNode(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = deleteNode(root->right, name);
    } else {
        // Node found
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            struct Node* temp = findMin(root->right);
            strcpy(root->name, temp->name);
            strcpy(root->phone, temp->phone);
            root->right = deleteNode(root->right, temp->name);
        }
    }
    return root;
}

// Search in BST
struct Node* search(struct Node* root, char name[]) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        return search(root->left, name);
    } else {
        return search(root->right, name);
    }
}

// In-order traversal (ascending)
void inorderAsc(struct Node* root) {
    if (root != NULL) {
        inorderAsc(root->left);
        printf("Name: %s, Phone: %s\n", root->name, root->phone);
        inorderAsc(root->right);
    }
}

// Reverse in-order (descending)
void inorderDesc(struct Node* root) {
    if (root != NULL) {
        inorderDesc(root->right);
        printf("Name: %s, Phone: %s\n", root->name, root->phone);
        inorderDesc(root->left);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    char name[50], phone[10];

    while (1) {
        printf("\n--- Phone Book Menu ---\n");
        printf("1. Add new entry\n");
        printf("2. Remove entry\n");
        printf("3. Search phone number\n");
        printf("4. List all entries (Ascending)\n");
        printf("5. List all entries (Descending)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                printf("Enter phone number: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = 0;
                root = insert(root, name, phone);
                break;

            case 2:
                printf("Enter name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                root = deleteNode(root, name);
                break;

            case 3:
                printf("Enter name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                struct Node* result = search(root, name);
                if (result) {
                    printf("Phone number of %s: %s\n", result->name, result->phone);
                } else {
                    printf("Contact not found!\n");
                }
                break;

            case 4:
                printf("\n--- Phone Book (Ascending Order) ---\n");
                inorderAsc(root);
                break;

            case 5:
                printf("\n--- Phone Book (Descending Order) ---\n");
                inorderDesc(root);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
//     roo