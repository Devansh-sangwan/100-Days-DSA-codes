#include <stdio.h>
#include <limits.h>

#define V 5

void dijkstra(int graph[V][V], int src) {
    int dist[V] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    int visited[V] = {0};

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] <= min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };

    dijkstra(graph, 0);
    return 0;
}