#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

//  create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert
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


// Compare
int isSame(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return 1;

    if (root1 == NULL || root2 == NULL)
        return 0;

    return (root1->data == root2->data) &&
           isSame(root1->left, root2->left) &&
           isSame(root1->right, root2->right);
}

int main() {
    struct Node* root1 = NULL;
    struct Node* root2 = NULL;
    int data, choice;

    // *************** First Tree ***************
    printf("Enter First Tree...\n");
    printf("Enter root node value: ");
    scanf("%d", &data);
    root1 = createNode(data);

    do {
        printf("Enter data to insert: ");
        scanf("%d", &data);
        insert(root1, data);

        printf("Do you want to insert more nodes? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
    } while (choice);

    // *************** Second Tree ***************
    printf("\nEnter Second Tree...\n");
    printf("Enter root node value: ");
    scanf("%d", &data);
    root2 = createNode(data);

    do {
        printf("Enter data to insert: ");
        scanf("%d", &data);
        insert(root2, data);

        printf("Do you want to insert more nodes? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
    } while (choice);

    // *************** Compare Trees ***************
    if (isSame(root1, root2))
        printf("\n The two trees are IDENTICAL.\n");
    else
        printf("\n The two trees are NOT identical.\n");

    return 0;
}