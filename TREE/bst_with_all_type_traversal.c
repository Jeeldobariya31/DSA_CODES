#include <stdio.h>
#include <stdlib.h>

//***************** Construct Node Section ..***********************
struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
//************************* Construct Tree Section..*************************
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}
//************************* Delate Node From  Tree Section..*************************
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        //  No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        //  One child
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
        // Two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); 
    return root;
}

//************************* Traversal Section ....********************************
//preorder
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
//inorder
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
//postorder
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
//************************** Menu For Handel Operation...... *************
int main() {
    struct Node* root = NULL;
    int data, choice;
    //root node creation 
     printf("Enter root node value: ");
     scanf("%d", & data);
     root = createNode(data);
     //add more nodes 
    do {
        printf("Enter data to insert: ");
        scanf("%d", &data);
         insert(root, data);

        printf("Do you want to insert more nodes? (1 for Yes / 0 for No): ");
        scanf("%d", &choice);
    } while (choice);
  // traversal and delation options
    int ch;
    do {
        printf("\n=> Select Choice For Traversal:\n");
        printf("=> Enter (1) For Inorder Traversal\n");
        printf("=> Enter (2) For Postorder Traversal\n");
        printf("=> Enter (3) For Preorder Traversal\n");
        printf("=> Enter (4) For Delate Node\n");
        printf("=> Enter (0) For Exit\n");
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
        case 4: int key;
                printf("Enter Data To delate : ");
                scanf("%d",&key)
                root =deleteNode(root, key);
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
