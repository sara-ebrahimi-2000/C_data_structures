#include "list.h"
#include <stdio.h>
#include <stdlib.h>

List stringToList(char *s) {
    if (s == NULL) return NULL;
    List head = NULL;
    List tail = NULL;

    for (int i = 0; s[i] != '\0'; i++) {  // ✅ s[i] not i
        if (s[i] >= 'A' && s[i] <= 'Z') {
            List newptr = malloc(sizeof(ListNode));
            newptr->data = s[i] - 'A' + 'a';
            newptr->next = NULL;

            if (head == NULL) {
                head = newptr;
                tail = newptr;
            } else {
                tail->next = newptr;
                tail = newptr;
            }
        }
    }
    return head;
}

void freelist(List l) {
    while (l != NULL) {
        List temp = l->next;
        free(l);    // ✅ free current, not next
        l = temp;
    }
}

int main() {
    List result = stringToList("AZbCuu12R");

    if (result == NULL || result->data != 'a')                                     { freelist(result); printf("TEST FAILED\n"); return 0; }
    if (result->next == NULL || result->next->data != 'z')                         { freelist(result); printf("TEST FAILED\n"); return 0; }
    if (result->next->next == NULL || result->next->next->data != 'c')             { freelist(result); printf("TEST FAILED\n"); return 0; }
    if (result->next->next->next == NULL || result->next->next->next->data != 'r') { freelist(result); printf("TEST FAILED\n"); return 0; }
    if (result->next->next->next->next != NULL)                                    { freelist(result); printf("TEST FAILED\n"); return 0; }

    freelist(result);
    printf("TEST PASSED\n");
    return 0;
}