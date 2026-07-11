
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node { int data; struct Node *next; } Node;
typedef Node *IntList;
 
Node *newNode(int v) {
    Node *n = malloc(sizeof(Node));
    n->data = v; n->next = NULL;
    return n;
}
 
void append(IntList *ls, int v) {
    Node *n = newNode(v);
    if (!*ls) { *ls = n; return; }
    Node *c = *ls;
    while (c->next) c = c->next;
    c->next = n;
}
 
void print(IntList ls) {
    while (ls) { printf("%d ", ls->data); ls = ls->next; }
    printf("\n");
}
 
IntList merge(IntList *ls1, IntList *ls2) {
        IntList result = NULL;
        IntList *tail= &result;
        while (*ls1 != NULL && *ls2 != NULL )
        {

           if( (*ls1)->data <= (*ls2)->data){
               *tail = *ls1;
               (*ls1) = (*ls1)->next;
           }else{
               *tail = *ls2;
               (*ls2) = (*ls2)->next;    
           }
           tail = &((*tail)->next);

        }
        if (*ls1 != NULL)
        {
           *tail = *ls1;
           *ls1 = NULL;
        }
        else if (*ls2 != NULL)
        {
            *tail = *ls2;
            *ls2 = NULL;
        }
        
        return result;      
}
 
int main(void) {
    IntList a = NULL, b = NULL;
    append(&a,1); append(&a,3); append(&a,5); append(&a,8);
    append(&b,2); append(&b,4); append(&b,6);

    IntList m = merge(&a, &b);
    print(m);
    return 0;
}