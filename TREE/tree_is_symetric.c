#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert 
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    int choice;
    printf("Where to insert %d? (1 for left, 2 for right) of node %d: ", value, root->data);
    scanf("%d", &choice);

    if (choice == 1)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}


int isSame(struct Node* left, struct Node* right) {
    if (left == NULL && right == NULL)
        return 1;
    if (left == NULL || right == NULL)
        return 0;

    return (left->data == right->data) &&
           isSame(left->left, right->right) &&
           isSame(left->right, right->left);
}

// symmetry 
int isSymmetric(struct Node* root) {
    if (root == NULL)
        return 1;
    return isSame(root->left, root->right);
}

int main() {
    struct Node* root = NULL;
    int data, choice;

    printf("Enter root node value: ");
    scanf("%d", &data);
    root = createNode(data);

    do {
        printf("Enter data to insert: ");
        scanf("%d", &data);
        insert(root, data);

        printf("Do you want to insert more nodes? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
    } while (choice);

    if (isSymmetric(root))
        printf("\n The tree is SYMMETRIC.\n");
    else
        printf("\n The tree is NOT symmetric.\n");

    return 0;
}