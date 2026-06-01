#include <stdio.h>
#include <stdlib.h>
typedef struct listnode ListNode,
*listnodePtr;

struct listnode {
    int data;
   listnodePtr next;
};
// pointer to first Node
typedef ListNode *List;


_Bool insert(List *l, int e) {
    if(l == NULL) {return 0;}
    if((*l == NULL) || e <= (*l)->data){
        
        //base case
        listnodePtr newptr = malloc(sizeof(ListNode));
        if(newptr == NULL) return 0;
        newptr->data = e;
        newptr->next = *l;
        *l = newptr;
        return 1;
    }
  //inductive case
   return insert(&(*l)->next,e);
}

void printList(listnodePtr l) {
    while (l != NULL) {
        printf("%d -> ", l->data);
        l = l->next;
    }
    printf("NULL\n");
}

int main() {

    listnodePtr head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    printList(head);

    return 0;
}
