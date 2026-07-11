
#include <stdlib.h>
#include <stdio.h>


typedef struct listNode ListNode, *List;

struct listNode {
    int data;
    List next;
};



typedef struct treeNode TreeNode, *Tree;

struct treeNode {
    Tree left;
    int data;
    Tree right;
};

/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
/* INSERT HERE MORE #include <...> IF NEEDED */

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */
/* INSERT HERE AUXILIARY FUNCTIONS IF NEEDED */

/**
 * Dato un albero binario t, restituire una nuova lista p (senza modificare t)
 * che contenga il percorso entro t che parte dalla radice, e procede a sinistra
 * se il valore in un nodo è dispari, e a destra altrimenti.
 *
 * Gli alberi sono rappresentati tramite parentesi, con "-" per indicare un figlio mancante.
 * Non considera l'eventualità che la malloc fallisca.
 *
 * ESEMPI (rappresentando le liste senza separare i caratteri, per compattezza):
 * (1) dato t={}, restituisce l=[]
 * (2) dato t={-1-}, restituisce l=[1]
 * (3) dato t={[-3-]1-[-4-]}, restituisce l=[1,3]
 * (4) dato t={[-3-]2-[-4-]}, restituisce l=[1,4]
 *
 * NOTA: questa funzione compare negli errori di compilazione come "student_parityPath"
 * NOTA: questa funzione viene testata indipendentemente dal vostro main
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * Given a binary tree t, return a new list p (without modifying t)
 * containing the path within t that starts from the root and proceeds
 * to the left if the value in a node is odd, and to the right otherwise.
 *
 * Trees are represented using parentheses, with "-" indicating a missing child.
 * It does not consider the possibility that malloc may fail.
 *
 * EXAMPLES (representing lists without separating characters, for compactness):
 * (1) given t={}, returns l=[]
 * (2) given t={-1-}, returns l=[1]
 * (3) given t={[-3-]1-[-4-]}, returns l=[1,3]
 * (4) given t={[-3-]2-[-4-]}, returns l=[1,4]
 *
 * NOTE: this function appears in compilation errors as "student_parityPath"
 * NOTE: this function is tested independently of your main
 * IMPORTANT: always try to make your code compile so you can see the
 * test results, even if it means commenting out part of this function's code
 * 
 */
 
 void freelist(List head){
     while(head != NULL){
         List next = head->next;
         free(head);
         head = next;
     }
 }
 void freeTree(Tree t) {
    if (t == NULL) return;
    freeTree(t->left);           /* free left subtree first  */
    freeTree(t->right);          /* free right subtree first */
    free(t);                     /* then free the node itself */
}
 List parityPath(Tree t) {
     
   
    List head = NULL; List tail = NULL;
    
    
    while(t != NULL){
    List newnode = malloc(sizeof(ListNode));
    newnode->data =t->data;
    newnode->next = NULL;
    
    if(head == NULL){ head = newnode; tail = newnode; }
    else{
        tail->next = newnode;
        tail = newnode;
    }
    if(t->data % 2 != 0){
        t = t->left;
    }else {
        t = t->right;
     }
    }
    return head;
  
}

/**
 * Invoca la funzione parityPath su uno o più casi a scelta, controllando che
 * il suo effetto come risultato e argomenti rispetti la specifica corretta.
 * Può essere sufficiente anche un unico caso, se sufficientemente generale per
 * individuare quali programmi sono corretti e quali no.
 * Se la funzione è corretta, come ultima cosa deve stampare "TEST PASSED\n".
 * Se invece la funzione non risulta corretta, deve stampare "TEST FAILED\n".
 * NON STAMPARE ALTRO SU STANDARD OUTPUT.
 * Se avete necessità di fare stampe di debug, potete farle su standard error.
 *
 * NOTA: dovete invocare "parityPath" e NON "student_parityPath"
 * NOTA: questa funzione compare negli errori di compilazione come "student_main"
 * NOTA: il main viene testato indipendentemente dalla vostra funzione parityPath
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * Invokes the parityPath function on one or more selected test cases, checking
 * that its effect as result and arguments respects the correct specification.
 * A single test case may be enough, if it sufficiently general to single out
 * which programs are correct and which are not.
 * If the function is correct, as the final step it must print "TEST PASSED\n".
 * If instead the function is not correct, it must print "TEST FAILED\n".
 * DO NOT PRINT ANYTHING ELSE ON STANDARD OUTPUT.
 * If you need to print debug information, use standard error.
 *
 * NOTE: you have to invoke "parityPath" and NOT "student_parityPath"
 * NOTE: this function appears in compilation errors as "student_main"
 * NOTE: the main is tested independently of your parityPath function
 * IMPORTANT: always try to make your code compile so that you can see the test
 * results, even if that means commenting out part of the code of this function
 */
int main() {

       /* --- build tree: 1 (odd→left→3) --- */
    Tree n3 = malloc(sizeof(TreeNode));
    n3->data = 3; n3->left = NULL; n3->right = NULL;

    Tree n4 = malloc(sizeof(TreeNode));
    n4->data = 4; n4->left = NULL; n4->right = NULL;

    Tree n1 = malloc(sizeof(TreeNode));
    n1->data = 1; n1->left = n3; n1->right = n4;

    List result = parityPath(n1);

    /* Check list is exactly [1, 3] in the correct ORDER */
    int passed =
        result != NULL &&
        result->data == 1 &&           /* first node must be 1, not 3 */
        result->next != NULL &&
        result->next->data == 3 &&     /* second node must be 3, not 1 */
        result->next->next == NULL;    /* no extra nodes */

    freelist(result);
    freeTree(n1);

    /* --- build tree: 2 (even→right→4) --- */
    Tree m3 = malloc(sizeof(TreeNode));
    m3->data = 3; m3->left = NULL; m3->right = NULL;

    Tree m4 = malloc(sizeof(TreeNode));
    m4->data = 4; m4->left = NULL; m4->right = NULL;

    Tree m1 = malloc(sizeof(TreeNode));
    m1->data = 2; m1->left = m3; m1->right = m4;

    List result2 = parityPath(m1);

    /* Check list is exactly [2, 4] in the correct ORDER */
    passed = passed &&
        result2 != NULL &&
        result2->data == 2 &&          /* first node must be 2 */
        result2->next != NULL &&
        result2->next->data == 4 &&    /* second node must be 4 */
        result2->next->next == NULL;

    freelist(result2);
    freeTree(m1);

    if (passed)
        printf("TEST PASSED\n");
    else
        printf("TEST FAILED\n");

    return 0;
 
}