#include <stdio.h>
#include <stdlib.h>

// ***************** Construct Node Section ***********************
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// ***************** Insert Section *****************
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Duplicate value %d not inserted.\n", value);
    return root;
}

// ***************** Find Minimum Node *****************
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// ***************** Delete Section *****************
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// ***************** Search Node *****************
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// ***************** Traversal Section *****************
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// ***************** Main Menu *****************
int main() {
    struct Node* root = NULL;
    int data, choice, ch, key;
    
    printf("Enter root node value: ");
    scanf("%d", &data);
    root = createNode(data);

    do {
        printf("Enter data to insert: ");
        scanf("%d", &data);
        root = insert(root, data);

        printf("Do you want to insert more nodes? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
    } while (choice);

    do {
        printf("\n===== BST Menu =====\n");
        printf("1. Inorder Traversal\n");
        printf("2. Postorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Delete Node\n");
        printf("5. Search Node\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("\nInorder Traversal: ");
            inorder(root);
            break;
        case 2:
            printf("\nPostorder Traversal: ");
            postorder(root);
            break;
        case 3:
            printf("\nPreorder Traversal: ");
            preorder(root);
            break;
        case 4:
            printf("Enter data to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;
        case 5:
            printf("Enter value to search: ");
            scanf("%d", &key);
            if (search(root, key) != NULL)
                printf("Node %d found in the tree.\n", key);
            else
                printf("Node %d not found in the tree.\n", key);
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
        printf("\n");
    } while (ch != 0);

    return 0;
}
