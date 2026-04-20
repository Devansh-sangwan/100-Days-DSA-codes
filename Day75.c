#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int maxLen = 0;

    // Hash map simulation
    int sum[MAX * 2];
    int index[MAX * 2];

    for (int i = 0; i < MAX * 2; i++) {
        index[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: sum = 0
        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        int key = prefixSum + MAX; // shift for negative

        if (index[key] != -1) {
            int len = i - index[key];
            if (len > maxLen)
                maxLen = len;
        } else {
            index[key] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}