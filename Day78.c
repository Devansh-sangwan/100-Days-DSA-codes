#include <stdio.h>
#include <limits.h>

#define MAX 1005

int n, m;
int graph[MAX][MAX];

int prim() {
    int visited[MAX] = {0};
    int key[MAX];

    // Initialize keys as infinite
    for (int i = 1; i <= n; i++)
        key[i] = INT_MAX;

    key[1] = 0; // start from node 1
    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int u = -1, min = INT_MAX;

        // Pick minimum key vertex not yet visited
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        visited[u] = 1;
        totalWeight += key[u];

        // Update keys of adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph with 0
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    printf("%d\n", prim());

    return 0;
}