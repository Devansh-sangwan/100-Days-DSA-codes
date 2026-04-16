#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS
void dfs(int node, int **adj, int *adjSize, bool *visited, int *stack, int *top) {
    visited[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, adj, adjSize, visited, stack, top);
        }
    }

    stack[(*top)++] = node;
}

// NOTE: edges[][2] — THIS IS IMPORTANT
void topoSort(int V, int edges[][2], int E) {

    int *adjSize = calloc(V, sizeof(int));

    // count edges
    for (int i = 0; i < E; i++) {
        adjSize[edges[i][0]]++;
    }

    // adjacency list
    int **adj = malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        if (adjSize[i] == 0)
            adj[i] = NULL;
        else
            adj[i] = malloc(adjSize[i] * sizeof(int));
        adjSize[i] = 0;
    }

    // fill graph
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][adjSize[u]++] = v;
    }

    bool *visited = calloc(V, sizeof(bool));
    int *stack = malloc(V * sizeof(int));
    int top = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, adjSize, visited, stack, &top);
        }
    }

    // print result
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// DRIVER (VERY IMPORTANT)
int main() {
    int V = 6;
    int E = 6;

    int edges[6][2] = {
        {5,2}, {5,0}, {4,0}, {4,1}, {2,3}, {3,1}
    };

    topoSort(V, edges, E);

    return 0;
}