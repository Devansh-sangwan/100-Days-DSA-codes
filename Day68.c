#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void topologicalSort(int n, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};
    int topo[MAX], index = 0;

    // Calculate in-degree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1)
                indegree[j]++;
        }
    }

    // Add nodes with 0 in-degree to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    // Process queue
    while (!isEmpty()) {
        int node = dequeue();
        topo[index++] = node;

        for (int j = 0; j < n; j++) {
            if (adj[node][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0)
                    enqueue(j);
            }
        }
    }

    // Check for cycle
    if (index != n) {
        printf("Cycle detected! Topological sort not possible.\n");
        return;
    }

    // Print result
    printf("Topological Order: ");
    for (int i = 0; i < n; i++)
        printf("%d ", topo[i]);
    printf("\n");
}

int main() {
    int n, adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort(n, adj);

    return 0;
}