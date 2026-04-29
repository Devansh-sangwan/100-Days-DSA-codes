#include <stdio.h>
#include <stdlib.h>

// Function for sorting
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Check if cows can be placed with minimum distance = dist
int canPlaceCows(int stalls[], int n, int k, int dist) {
    int count = 1; // First cow in first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];
        }

        if (count >= k)
            return 1;
    }

    return 0;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int stalls[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Sort stall positions
    qsort(stalls, n, sizeof(int), compare);

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    // Binary Search on answer
    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlaceCows(stalls, n, k, mid)) {
            ans = mid;
            low = mid + 1; // Try bigger distance
        } else {
            high = mid - 1; // Reduce distance
        }
    }

    printf("%d\n", ans);

    return 0;
}