#include <stdio.h>

#include "list.h"

/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
/* INSERT HERE MORE #include <...> IF NEEDED */

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */
/* INSERT HERE AUXILIARY FUNCTIONS IF NEEDED */

/**
 * Date due liste di caratteri l ed r, restituire una nuova lista p (senza
 * modificare le liste l ed r) che contenga il più lungo prefisso di l per
 * cui nessun suo carattere ha un carattere uguale nella posizione
 * corrispondente di r.
 * 
 * Si definisce "prefisso" di una lista una qualunque sotto-lista di nodi dall'inizio.
 * Non considera l'eventualità che la malloc fallisca.
 *
 * ESEMPI (rappresentando le liste senza separare i caratteri, per compattezza):
 * (1) date l=[] e s=[], restituisce p=[]
 * (2) date l=[] e s=[p,i,p,p,o], restituisce p=[]
 * (3) date l=[p,i,p,p,o] e s=[], restituisce p=[p,i,p,p,o]
 * (4) date l=[p,i,p,p,o] e s=[p,i,p,p,o], restituisce p=[]
 * (5) date l=[s,u,p,e,r,p,i,p,p,o] e s=[p,l,u,t,o], restituisce p=[s,u,p,e,r,p,i,p,p,o]
 * (6) date l=[p,l,u,t,o] e s=[s,u,p,e,r,p,i,p,p,o], restituisce p=[p,l,u,t,o]
 * (7) date l=[s,u,p,e,r,p,i,p,p,o] e s=[p,i,p,p,o], restituisce p=[s,u], perché la p seguente è in comune
 * (8) date l=[p,i,p,p,o] e s=[s,u,p,e,r,p,i,p,p,o], restituisce p=[p,i], perché la p seguente è in comune
 * 
 * NOTA: questa funzione compare negli errori di compilazione come "student_antiPrefix"
 * NOTA: questa funzione viene testata indipendentemente dal vostro main
 * NOTA: viene controllato che questa funzione gestisca correttamente la memoria
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * Given two character lists l and r, return a new list p (without
 * modifying lists l and r) containing the longest prefix of l such
 * that none of its characters has an identical character in the
 * corresponding position of r.
 *
 * A "prefix" of a list is defined as any sublist of nodes starting from the beginning.
 * It does not consider the possibility that malloc may fail.
 *
 * EXAMPLES (representing lists without separating characters, for compactness):
 * (1) given l=[] and s=[], returns p=[]
 * (2) given l=[] and s=[p,i,p,p,o], returns p=[]
 * (3) given l=[p,i,p,p,o] and s=[], returns p=[p,i,p,p,o]
 * (4) given l=[p,i,p,p,o] and s=[p,i,p,p,o], returns p=[]
 * (5) given l=[s,u,p,e,r,p,i,p,p,o] and s=[p,l,u,t,o], returns p=[s,u,p,e,r,p,i,p,p,o]
 * (6) given l=[p,l,u,t,o] and s=[s,u,p,e,r,p,i,p,p,o], returns p=[p,l,u,t,o]
 * (7) given l=[s,u,p,e,r,p,i,p,p,o] and s=[p,i,p,p,o], returns p=[s,u], because the following p is shared
 * (8) given l=[p,i,p,p,o] and s=[s,u,p,e,r,p,i,p,p,o], returns p=[p,i], because the following p is shared
 *
 * NOTE: this function appears in compilation errors as "student_antiPrefix"
 * NOTE: this function is tested independently of your main
 * NOTE: this function also has to correctly handle memory allocation and freeing
 * IMPORTANT: always try to make your code compile so that you can see the test
 * results, even if that means commenting out part of the code of this function
 */
void freelist(List l){
    while(l != NULL){
        List tem = l->next;
        free(l);
        l = tem;
    }
    
}

List antiPrefix(List l, List r) {
   List head = NULL;
   List tail = NULL;
   
   while(l != NULL && ( r == NULL || l->data != r->data)){
       List newptr=malloc(sizeof(ListNode));
       newptr->data = l->data;
       newptr->next = NULL;
       if(head == NULL){
           head = newptr;
           tail = newptr;
       }
       else{
           tail->next = newptr;
           tail = newptr;
       }
       l = l->next;                 // move to next node in l
     if (r != NULL) r = r->next;  // move to next node in r (if it exists)
   }
   
  return head;
}


/**
 * Invoca la funzione "antiPrefix" su uno o più casi a scelta, controllando che
 * il suo effetto come risultato e argomenti rispetti la specifica corretta.
 * Può essere sufficiente anche un unico caso, se sufficientemente generale per
 * individuare quali programmi sono corretti e quali no.
 * Se la funzione è corretta, come ultima cosa deve stampare "TEST PASSED\n".
 * Se invece la funzione non risulta corretta, deve stampare "TEST FAILED\n".
 * NON STAMPARE ALTRO SU STANDARD OUTPUT.
 * Se avete necessità di fare stampe di debug, potete farle su standard error.
 *
 * NOTA: questa funzione compare negli errori di compilazione come "student_main"
 * NOTA: il main viene testato indipendentemente dalla vostra funzione "antiPrefix"
 * NOTA: viene controllato che questa funzione gestisca correttamente la memoria
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * Invokes the "antiPrefix" function on one or more selected test cases, checking
 * that its effect as result and arguments respects the correct specification.
 * A single test case may be enough, if it sufficiently general to single out
 * which programs are correct and which are not.
 * If the function is correct, as the final step it must print "TEST PASSED\n".
 * If instead the function is not correct, it must print "TEST FAILED\n".
 * DO NOT PRINT ANYTHING ELSE ON STANDARD OUTPUT.
 * If you need to print debug information, use standard error.
 *
 * NOTE: this function appears in compilation errors as "student_main"
 * NOTE: the main is tested independently of your "antiPrefix" function
 * NOTE: this function also has to correctly handle memory allocation and freeing
 * IMPORTANT: always try to make your code compile so that you can see the test
 * results, even if that means commenting out part of the code of this function
 */
int main() {
      int pass = 1;
      char lc[] = {'s','u','p','e','r','p','i','p','p','o'};
      char rc[] = {'p','i','p','p','o'};
      
      List l = NULL;
      List r = NULL;
      
      for(int i = 9; i>=0;i--){
         List n=malloc(sizeof(ListNode)); n->data = lc[i]; n->next = l; l = n; 
         }
        
       for(int i = 4; i>=0;i--){
         List n=malloc(sizeof(ListNode)); n->data = rc[i]; n->next = r ; r = n; 
         }
      
      List p = antiPrefix(l,r);
      
      
      pass = pass &&  p!=NULL && p->data =='s' && p->next != NULL && p->next->data == 'u' && p->next->next == NULL;
      
      freelist(l);
      freelist(r);
      freelist(p);
      
      if(pass){
        printf("TEST PASSED\n"); 
      }else{
       printf("TEST FAILED\n");
      }
      

      return 0;
}