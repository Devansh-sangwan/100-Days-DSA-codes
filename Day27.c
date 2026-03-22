#include <stdio.h>
#include <stdlib.h>

// Definition of Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to get length of list
int getLength(struct Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

// Function to find intersection point
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Move pointer of longer list ahead
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < len2 - len1; i++)
            ptr2 = ptr2->next;
    }

    // Traverse both lists together
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {   // ✅ Correct comparison
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

// Function to print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


int main() {
  
    struct Node* common = newNode(4);
    common->next = newNode(5);

    
    struct Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = common;

    
    struct Node* head2 = newNode(9);
    head2->next = common;

    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

  
    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        printf("Intersection at node with data: %d\n", intersection->data);
    else
        printf("No intersection found\n");

    return 0;
}