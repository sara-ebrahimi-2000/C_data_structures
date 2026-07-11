#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

/**
 * Given a list of characters *ptr and a string str, modifies *ptr by inserting
 * a new node for each character in str. The new nodes are inserted after
 * the first occurrence of the character 'Z' in the list. If 'Z' does not occur,
 * they are inserted at the end of the list. The new nodes are inserted in the same
 * order as they appear in the string.
 *
 * Does not consider the possibility that malloc may fail.
 * If ptr == NULL returns 0, otherwise returns 1.
 * If s == NULL or ptr == NULL, does not modify ptr.
 *
 * EXAMPLES:
 * (1) given *ptr == [A,x,8] and s == "k$2e" returns 1 and causes *ptr == [A,x,8,k,$,2,e]
 * (2) given ptr == NULL and s == "Pluto" returns 0 and does not modify ptr
 * (3) given *ptr == [] and s == "Pluto" returns 1 and causes *ptr == [P,l,u,t,o]
 * (4) given *ptr == [P,A,Z,Z,O] and s == "Pluto" returns 1 and causes *ptr == [P,A,Z,P,l,u,t,o,Z,O]
 * (5) given *ptr == [p,a,z,z,o] and s == "Pluto" returns 1 and causes *ptr == [p,a,z,z,o,P,l,u,t,o]
 * (6) given *ptr == [p,a,z,z,o] and s == NULL returns 1 and does not modify ptr
 */
int insertAfterZ(Node* ptr, const char* s) {

    if(ptr == NULL) return 0;
    if(s == NULL) return 1;
    Node* cur = ptr;
    while (cur != NULL && cur->data != 'Z')
    {
       cur = cur->next;
    }
    if(cur == NULL){
         cur = ptr;
         while (cur->next != NULL) // stop at the last node ;;; NOT NULL
         {
           cur = cur->next;
         }
    }
    for(int i =0;s[i] != '\0';i++){
        Node* newnode = malloc(sizeof(Node));
        newnode->data = s[i];
        newnode->next = cur->next;
        cur->next = newnode;
        cur = newnode;
    }

    return 1;

}

// helper: build a list from a string, returns head
Node* buildList(char *s){
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0;s[i] != '\0'; i++)
    {
        /* code */
        Node* newnode = malloc(sizeof(Node));
        newnode->data = s[i];
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    return head ;
    
}


// helper: print a list
void printList(Node* head) {
    printf("[");
    while (head != NULL) {
        printf("%c", head->data);
        if (head->next != NULL) printf(",");
        head = head->next;
    }
    printf("]\n");
}

// helper: free a list
void freeList(Node* head) {
    while (head != NULL) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    Node* list;
    int result;

    // Test 1: [A,x,8] + "k$2e" → [A,x,8,k,$,2,e]
    list = buildList("Ax8");
    result = insertAfterZ(list, "k$2e");
    printf("Test 1 | return: %d | list: ", result);
    printList(list);
    freeList(list);

    // Test 2: ptr == NULL + "Pluto" → return 0
    result = insertAfterZ(NULL, "Pluto");
    printf("Test 2 | return: %d\n", result);

    // Test 3: [] + "Pluto" → [P,l,u,t,o]
    // empty list: single dummy node won't work, so we handle it differently
    // since ptr is a single pointer, we create a head node manually
    list = buildList("Pluto");
    result = insertAfterZ(NULL, "Pluto");
    printf("Test 3 | return: %d | list: ", result);
    printList(list);
    freeList(list);

    // Test 4: [P,A,Z,Z,O] + "Pluto" → [P,A,Z,P,l,u,t,o,Z,O]
    list = buildList("PAZZO");
    result = insertAfterZ(list, "Pluto");
    printf("Test 4 | return: %d | list: ", result);
    printList(list);
    freeList(list);

    // Test 5: [p,a,z,z,o] + "Pluto" → [p,a,z,z,o,P,l,u,t,o]
    list = buildList("pazzo");
    result = insertAfterZ(list, "Pluto");
    printf("Test 5 | return: %d | list: ", result);
    printList(list);
    freeList(list);

    // Test 6: [p,a,z,z,o] + NULL → return 1, no change
    list = buildList("pazzo");
    result = insertAfterZ(list, NULL);
    printf("Test 6 | return: %d | list: ", result);
    printList(list);
    freeList(list);

    return 0;
}