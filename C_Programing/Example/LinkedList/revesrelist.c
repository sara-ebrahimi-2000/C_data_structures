
#include <stdio.h>
#include <stdlib.h>

typedef struct intNode {
    int data;
    struct intNode *next;
} IntNode;

typedef IntNode *IntList;

/* Create a new node */
IntList createNode(int value) {
    IntList n = malloc(sizeof(IntNode));

    if (n == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    n->data = value;
    n->next = NULL;

    return n;
}

/* Print the list */
void printList(IntList ls) {
    while (ls != NULL) {
        printf("%d ", ls->data);
        ls = ls->next;
    }
    printf("\n");
}

/* Reverse the list */
void reverse(IntList *lsPtr) {
    IntList prev = NULL;
    IntList curr = *lsPtr;
    IntList next = NULL;

    while (curr != NULL)
    {
        /* code */
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }
   *lsPtr = prev;
}

int main() {

    IntList ls = createNode(1);
    ls->next = createNode(2);
    ls->next->next = createNode(3);
    ls->next->next->next = createNode(4);

    printf("Original list: ");
    printList(ls);

    reverse(&ls);

    printf("Reversed list: ");
    printList(ls);

    return 0;
}