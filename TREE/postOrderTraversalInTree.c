#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

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

void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
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

    printf("\npostorder Traversal of Tree: ");
    postorder(root);
    printf("\n");

    return 0;
}
