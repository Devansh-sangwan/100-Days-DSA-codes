#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void bfs(int s, struct Node* adj[], int n) {
    int visited[n];
    int queue[n];
    int front = 0, rear = 0;

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    visited[s] = 1;
    queue[rear++] = s;

    while(front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        struct Node* temp = adj[v];
        while(temp != NULL) {
            int neighbor = temp->vertex;

            if(!visited[neighbor]) {
                visited[neighbor] = 1;
                queue[rear++] = neighbor;
            }

            temp = temp->next;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int s;
    scanf("%d", &s);

    printf("BFS Traversal: ");
    bfs(s, adj, n);

    return 0;
}