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
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ----------- Preorder + Postorder ------------
struct Node *constructTreePrePost(int preorder[], int postorder[], int preStart, int preEnd, int postStart, int postEnd) {
    if (preStart > preEnd || postStart > postEnd) {
        return NULL;
    }

    struct Node* root = createNode(preorder[preStart]);

    if (preStart == preEnd) {
        return root;
    }

    // Next element in preorder[] is always left child
    int leftChild = preorder[preStart + 1];
    int leftChildIndex = -1;

    // Find left child index in postorder[]
    for (int i = postStart; i <= postEnd; i++) {
        if (postorder[i] == leftChild) {
            leftChildIndex = i;
            break;
        }
    }

    if (leftChildIndex == -1) {
        printf("Error: Invalid preorder/postorder input.\n");
        return root;
    }

    int leftSubtreeSize = leftChildIndex - postStart + 1;

    // Build left subtree
    root->left = constructTreePrePost(
        preorder, postorder,
        preStart + 1, preStart + leftSubtreeSize,
        postStart, leftChildIndex
    );

    // Build right subtree
    root->right = constructTreePrePost(
        preorder, postorder,
        preStart + leftSubtreeSize + 1, preEnd,
        leftChildIndex + 1, postEnd - 1
    );

    return root;
}

// ----------- Traversals ------------
void printInorder(struct Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    printf("Enter no of nodes in tree: ");
    int n;
    scanf("%d", &n);

    int preorder[n], postorder[n];

    printf("Enter Preorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    printf("Enter Postorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    printf("======== Tree from Preorder + Postorder ======\n");
    struct Node* root3 = constructTreePrePost(preorder, postorder, 0, n - 1, 0, n - 1);
    printf("Inorder Traversal: ");
    printInorder(root3);
    printf("\n");
    return 0;
}
