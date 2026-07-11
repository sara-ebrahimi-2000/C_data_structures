

#include <stdio.h>
#include "list.h"

/* INSERIRE QUI EVENTUALI ALTRI #include <...> */
/* INSERT HERE MORE #include <...> IF NEEDED */

/* INSERIRE QUI EVENTUALI FUNZIONI AUSILIARIE */
/* INSERT HERE AUXILIARY FUNCTIONS IF NEEDED */

/**
 * Dati due array di interi a e b di uguale lunghezza n, restituire una lista
 * di 2*n interi che contiene nell’ordine gli interi a[0], b[n-1], a[1], b[n-2],
 * ... a[n-2], b[1], a[n-1], b[0].
 * Quindi, alterna gli interi di a con quelli di b in ordine inverso.
 *
 * Non considera l'eventualità che la malloc fallisca.
 * Si assuma che a != NULL, b != NULL.
 *
 * ESEMPI:
 * (1) dati a=[], b=[], n=0 restituisce []
 * (2) dati a=[5], b=[3], n=1 restituisce [5, 3]
 * (2) dati a=[10, 20], b=[1, 2], n=2 restituisce [10, 2, 20, 1]
 * (4) dati a=[1, 2, 3, 4], b=[6, 7, 8, 9], n=4 restituisce [1, 9, 2, 8, 3, 7, 4, 6]
 *
 * NOTA: questa funzione compare negli errori di compilazione come "student_arrayMerge"
 * NOTA: questa funzione viene testata indipendentemente dal vostro main
 * NOTA: viene controllato che questa funzione gestisca correttamente la memoria
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * Given two integer arrays a and b of identical length n, return a list of
 * 2*n integers containing (in order) integers a[0], b[n-1], a[1], b[n-2],
 * ... a[n-2], b[1], a[n-1], b[0].
 * That is, it alternates the integers from a with those from b in reverse order.
 *
 * It does not consider the possibility that malloc may fail.
 * Assume that a != NULL, b != NULL.
 *
 * EXAMPLES:
 * (1) given a=[], b=[], n=0 returns []
 * (2) given a=[5], b=[3], n=1 returns [5, 3]
 * (2) given a=[10, 20], b=[1, 2], n=2 returns [10, 2, 20, 1]
 * (4) given a=[1, 2, 3, 4], b=[6, 7, 8, 9], n=4 returns [1, 9, 2, 8, 3, 7, 4, 6]
 *
 * NOTE: this function appears in compilation errors as "student_arrayMerge"
 * NOTE: this function is tested independently of your main
 * NOTE: this function also has to correctly handle memory allocation and freeing
 * IMPORTANT: always try to make your code compile so that you can see the test
 * results, even if that means commenting out part of the code of this function
 */
List arrayMerge(int *a, int *b, int n) {
    List head = NULL;
  
    int i =0;
    int j =n-1;
    while( i < n && j >= 0  ){
        List cur = head;
        List newnode1 = malloc(sizeof(ListNode));
        List newnode2 = malloc(sizeof(ListNode));
        
        newnode1->data = a[i];
        newnode1->next = newnode2;
        newnode2->data =a[j];
        newnode2->next = NULL;
        
        
        if(cur == NULL){
            cur = newnode1;
         
        }else{
            cur->next->next = newnode1; // mo
            cur = newnode1;
        }
        i++;
        j--;
    }
    
    return head;

}

void freelist(List head){
    while(head != NULL){
        List tem = head->next;
        free(head);
        head = tem;
    }
    
}


/**
 * Invoca la funzione "arrayMerge" su uno o più casi a scelta, controllando che
 * il suo effetto come risultato e argomenti rispetti la specifica corretta.
 * Può essere sufficiente anche un unico caso, se sufficientemente generale per
 * individuare quali programmi sono corretti e quali no.
 * Se la funzione è corretta, come ultima cosa deve stampare "TEST PASSED\n".
 * Se invece la funzione non risulta corretta, deve stampare "TEST FAILED\n".
 * NON STAMPARE ALTRO SU STANDARD OUTPUT.
 * Se avete necessità di fare stampe di debug, potete farle su standard error.
 *
 * NOTA: questa funzione compare negli errori di compilazione come "student_main"
 * NOTA: il main viene testato indipendentemente dalla vostra funzione "arrayMerge"
 * NOTA: viene controllato che questa funzione gestisca correttamente la memoria
 * IMPORTANTE: cercate sempre di far compilare il vostro codice per poter vedere il
 * risultato dei test, anche a costo di commentare parte del codice di questa funzione
 *
 * <ENGLISH VERSION>
 *
 * Invokes the "arrayMerge" function on one or more selected test cases, checking
 * that its effect as result and arguments respects the correct specification.
 * A single test case may be enough, if it sufficiently general to single out
 * which programs are correct and which are not.
 * If the function is correct, as the final step it must print "TEST PASSED\n".
 * If instead the function is not correct, it must print "TEST FAILED\n".
 * DO NOT PRINT ANYTHING ELSE ON STANDARD OUTPUT.
 * If you need to print debug information, use standard error.
 *
 * NOTE: this function appears in compilation errors as "student_main"
 * NOTE: the main is tested independently of your "arrayMerge" function
 * NOTE: this function also has to correctly handle memory allocation and freeing
 * IMPORTANT: always try to make your code compile so that you can see the test
 * results, even if that means commenting out part of the code of this function
 */
int main() {
    int n =4;
    int a[] = {1, 2, 3, 4};
    int b[] = {6, 7, 8, 9};
    List result =  arrayMerge(a, b, n);
    
    int m = 8;
    int c[]= {1, 9, 2, 8, 3, 7, 4, 6};
    
    
    
    //Test 1
    
    int pass = 1;
       
 
     for(int i = 0;i < m;i++){
        if(c[i] != result->data){
          pass = 0;
        }
        result = result->next;
     }
      
     
     
      freelist(result);
      if(pass){
          
           printf("TEST PASSED\n");
      }else{
           
          printf("TEST FAILED\n");
      }


    return 0;
}