#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}
// Without recursion

void findSmallest(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    while (root->left != NULL) root = root->left;
    printf("smallest (direct) = %d\n", root->data);
}
void findLargest(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    while (root->right != NULL) root = root->right;
    printf("largest (direct) = %d\n", root->data);
}
// With Recursion

void findSmallestRec(struct Node* root) {
     if (root == NULL){
        printf("Tree is empty\n");
        return;
    } 
    if (root->left == NULL){
        printf("smallest (recursive) = %d\n", root->data);
        return;
    }
    return findSmallestRec(root->left);
}

void findLargestRec(struct Node* root) {
    if (root == NULL){
        printf("Tree is empty\n");
        return;
    } 
    if (root->right == NULL){
        printf("largest (recursive) = %d\n", root->data);
        return;
    }
    return findLargestRec(root->right);
}


int main() {
    struct Node* root = NULL;
    int n;
    printf("Enter number of elements to insert in bst: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }
    findSmallest(root);
    findLargest(root);
    findSmallestRec(root);
    findLargestRec(root);

    return 0;
}


