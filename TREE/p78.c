#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to calculate height and check balance
int height(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    if (leftHeight == -1) // Left subtree is unbalanced
        return -1;

    int rightHeight = height(root->right);
    if (rightHeight == -1) // Right subtree is unbalanced
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1; // Current node is unbalanced

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Main function to check if the tree is height-balanced
bool isBalanced(struct TreeNode* root) {
    return height(root) != -1;
}

// Example usage
int main() {
  
    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    if (isBalanced(root))
        printf("TRUE\n");
    else
        printf("FALSE\n");

    return 0;
}
