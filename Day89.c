#include <stdio.h>

int isPossible(int books[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {

        // If a single book has more pages than maxPages
        if (books[i] > maxPages)
            return 0;

        // Add pages to current student
        if (pagesSum + books[i] <= maxPages) {
            pagesSum += books[i];
        }
        else {
            // Allocate to next student
            students++;
            pagesSum = books[i];

            // If students exceed limit
            if (students > m)
                return 0;
        }
    }

    return 1;
}

int allocateBooks(int books[], int n, int m) {

    // If students are more than books
    if (m > n)
        return -1;

    int low = 0, high = 0, ans = -1;

    // Calculate total pages
    for (int i = 0; i < n; i++) {
        high += books[i];
    }

    // Binary Search
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(books, n, m, mid)) {
            ans = mid;
            high = mid - 1; // Try smaller value
        }
        else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    int books[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &books[i]);
    }

    printf("%d", allocateBooks(books, n, m));

    return 0;
}