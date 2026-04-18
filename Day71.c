#include <stdio.h>
#include <string.h>

#define EMPTY -1

int hashTable[100];

// Insert using quadratic probing
void insert(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (hashTable[index] == EMPTY) {
            hashTable[index] = key;
            return;
        }
        i++;
    }
}

// Search using quadratic probing
int search(int key, int m) {
    int i = 0;
    int index;

    while (i < m) {
        index = (key % m + i * i) % m;

        if (hashTable[index] == EMPTY)
            return 0;  // NOT FOUND

        if (hashTable[index] == key)
            return 1;  // FOUND

        i++;
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    // Initialize table
    for (int i = 0; i < m; i++)
        hashTable[i] = EMPTY;

    char op[10];
    int key;

    while (q--) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(key, m))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}