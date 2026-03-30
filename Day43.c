#include <stdio.h>
#include <stdlib.h>

/* Tree Node */
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

/* Queue for level order construction */
Node* queue[1000];
int front = 0, rear = -1;

void enqueue(Node* node) {
    queue[++rear] = node;
}

Node* dequeue() {
    return queue[front++];
}

/* Create new node */
Node* createNode(int val) {
    if (val == -1) return NULL;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Build tree from level order */
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Node* root = createNode(arr[0]);
    enqueue(root);

    int i = 1;

    while (i < n) {
        Node* current = dequeue();

        /* Left child */
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        /* Right child */
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }

    return root;
}

/* Inorder Traversal */
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    Node* root = buildTree(arr, N);

    inorder(root);

    return 0;
}