#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
bool dfs(int node, int **adj, int *adjSize, bool *visited, bool *recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, adjSize, visited, recStack))
                return true;
        } 
        else if (recStack[neighbor]) {
            return true; // cycle found
        }
    }

    recStack[node] = false; // IMPORTANT
    return false;
}

void detectCycle(int edges[][2], int E, int V) {
    // Step 1: count outgoing edges
    int *adjSize = (int*)calloc(V, sizeof(int));
    for (int i = 0; i < E; i++) {
        adjSize[edges[i][0]]++;
    }

    // Step 2: allocate adjacency list
    int **adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        if (adjSize[i] == 0) {
            adj[i] = NULL; // IMPORTANT FIX
        } else {
            adj[i] = (int*)malloc(adjSize[i] * sizeof(int));
        }
        adjSize[i] = 0; // reset
    }

    // Step 3: fill adjacency list
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][adjSize[u]++] = v;
    }

    // Step 4: visited arrays
    bool *visited = (bool*)calloc(V, sizeof(bool));
    bool *recStack = (bool*)calloc(V, sizeof(bool));

    // Step 5: check all nodes
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack)) {
                printf("YES\n");
                return;
            }
        }
    }

    printf("NO\n");
}

// 🔽 DRIVER CODE (ADD THIS if missing)
int main() {
    int V = 4;
    int E = 4;

    int edges[4][2] = {
        {0,1}, {1,2}, {2,3}, {3,1}
    };

    detectCycle(edges, E, V);

    return 0;
}