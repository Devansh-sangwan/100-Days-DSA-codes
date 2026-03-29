#include <stdio.h>
#include <stdlib.h>

/* Node structure */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

/* Enqueue operation */
void enqueue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

/* Dequeue operation */
int dequeue() {
    if (front == NULL) {
        return -1;
    }

    Node* temp = front;
    int value = temp->data;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return value;
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'e') {  // enqueue
            int x;
            scanf("%d", &x);
            enqueue(x);
        } else {             // dequeue
            printf("%d\n", dequeue());
        }
    }

    return 0;
}