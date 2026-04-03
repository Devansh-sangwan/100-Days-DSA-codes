#include <stdio.h>
#include <stdlib.h>

// Structure for BST node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Search in BST
struct TreeNode* searchBST(struct TreeNode* root, int key) {
    if (root == NULL || root->val == key)
        return root;

    if (key < root->val)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    struct TreeNode* root = NULL;

    // Insert nodes
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int key;
    scanf("%d", &key);

    struct TreeNode* result = searchBST(root, key);

    if (result != NULL)
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}