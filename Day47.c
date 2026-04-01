#include <stdio.h>
#include <stdlib.h>

// Definition of tree node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate height
int height(struct TreeNode* root) {
    // Base case
    if (root == NULL)
        return 0;

    // Recursive calls
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Return max + 1
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int main() {
    

    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    // Calculate height
    int h = height(root);

    // Output
    printf("Height of Binary Tree = %d\n", h);

    return 0;
}