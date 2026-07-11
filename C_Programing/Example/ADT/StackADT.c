#include <stdio.h>
#include <stdlib.h>

/*
    Create a node type for the linked list.
    
    Each node contains:
    - a character (data)
    - a pointer to the next node
*/
typedef struct listnode ListNode,
*listNodeptr;

/* Node structure */
struct listnode {
    char data;          // Character stored in the node
    listNodeptr next;   // Pointer to next node
};

/*
    Stack structure
    
    top  -> points to the first node of the stack
    size -> number of elements in the stack
*/
struct charstack {
    listNodeptr top;
    int size;
};

/* Define stack pointer type */
typedef struct charstack *charstackADT;

/*
    mkstack()
    
    Creates a new empty stack.
*/
charstackADT mkstack() {

    // Allocate memory for the stack structure
    charstackADT s = malloc(sizeof(*s));

    // Check if memory allocation failed
    if(s == NULL)
        return NULL;

    // Initially the stack is empty
    s->top = NULL;

    // Initial size is 0
    s->size = 0;

    return s;
}

/*
    push()
    
    Adds a new element on top of the stack.
    
    Returns:
    1 -> success
    0 -> memory allocation failed
*/
_Bool push(charstackADT s, char e) {

    // Create a new node
    listNodeptr ptr = malloc(sizeof(*ptr));

    // Check allocation
    if(ptr == NULL)
        return 0;

    // Store the element inside the node
    ptr->data = e;

    /*
        New node points to the old top
        
        Example:
        
        Before:
        top -> A
        
        After push(B):
        top -> B -> A
    */
    ptr->next = s->top;

    // Update top pointer
    s->top = ptr;

    // Increase size
    s->size++;

    return 1;
}

/*
    dsStack()
    
    Frees all memory used by the stack.
    
    We pass:
    charstackADT *ps
    
    because we also want to set the original
    stack pointer to NULL after freeing it.
*/
void dsStack(charstackADT *ps) {

    // Start from the top node
    listNodeptr current = (*ps)->top;

    // Traverse the linked list
    while(current != NULL) {

        // Save current node
        listNodeptr temp = current;

        // Move to next node
        current = current->next;

        // Free old node
        free(temp);
    }

    // Free the stack structure itself
    free(*ps);

    // Avoid dangling pointer
    *ps = NULL;
}

/*
    isEmpty()
    
    Checks whether the stack is empty.
    
    Returns:
    1 -> empty
    0 -> not empty
*/
_Bool isEmty(charstackADT s) {

    return (s->top == NULL);
}

/*
    pop()
    
    Removes and returns the top element.
*/
char pop(charstackADT s) {

    // Cannot pop from an empty stack
    if(isEmty(s)) {
        exit(EXIT_FAILURE);
    }

    // Save top element
    char e = s->top->data;

    /*
        Move top to next node
        
        Example:
        
        Before:
        top -> C -> B -> A
        
        After pop:
        top -> B -> A
    */
    s->top = s->top->next;

    // Decrease size
    s->size--;

    // Return removed element
    return e;
}

/*
    Main function
*/
int main() {

    // Create stack
    charstackADT s = mkstack();

    // Push elements
    push(s, 'a');
    push(s, 'b');
    push(s, 'c');

    /*
        Stack now:
        
        top -> c -> b -> a
    */

    // Remove top element ('c')
    pop(s);

    /*
        Stack now:
        
        top -> b -> a
    */

    // Free all memory
    dsStack(&s);

    return 0;
}
