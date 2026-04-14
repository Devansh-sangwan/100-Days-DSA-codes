#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];
int adj[MAX][MAX];
int V;

// DFS function with parent tracking
int dfs(int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) { // if edge exists
            if (!visited[i]) {
                if (dfs(i, node))
                    return 1;
            }
            else if (i != parent) {
                return 1; // cycle found
            }
        }
    }
    return 0;
}

int hasCycle() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    int E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}