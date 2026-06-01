#include <stdio.h>
#include <stdlib.h>

typedef struct listnode ListNode,
*ListNodeptr;

struct listnode{
    int data;
    ListNodeptr next;
};

void add(ListNodeptr *s, int e){

    ListNodeptr newptr = malloc(sizeof(*newptr));

    if(newptr == NULL)
        return;

    newptr->data = e;
    newptr->next = *s;

    *s = newptr;
}

void printlist(ListNodeptr l){

    // base case
    if(l == NULL)
        return;

    // print current node
    printf("The data is %d\n", l->data);

    // recursive call
    printlist(l->next);
}

int main() {

    ListNodeptr s = NULL;

    add(&s,12);
    add(&s,13);
    add(&s,14);
    add(&s,15);

    printlist(s);

    return 0;
}
