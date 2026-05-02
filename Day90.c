#include <stdio.h>

int canAllocate(int books[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {

        // If one book has more pages than maxPages
        if (books[i] > maxPages)
            return 0;

        // Add book to current student
        if (pagesSum + books[i] <= maxPages) {
            pagesSum += books[i];
        }
        else {
            // Allocate to next student
            students++;
            pagesSum = books[i];

            // If students exceed m
            if (students > m)
                return 0;
        }
    }

    return 1;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    int books[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }

    int low = books[0];
    int high = 0;

    // Find max element and total sum
    for (int i = 0; i < n; i++) {
        if (books[i] > low)
            low = books[i];

        high += books[i];
    }

    int ans = high;

    // Binary Search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(books, n, m, mid)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    printf("%d", ans);

    return 0;
}