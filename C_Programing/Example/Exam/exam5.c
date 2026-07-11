
#include <stdio.h>
#include <stdlib.h>

/* -------------------------------
   TIPOLOGIE E STRUTTURE
   ------------------------------- */

/* forward declarations */
typedef struct Node Node;
typedef struct List List;

/* typedef per i puntatori richiesti (SENZA doppi puntatori) */
typedef Node *NodePtr;   /* NodePtr = Node* (puntatore a Node) */
typedef List *ListPtr;   /* ListPtr = List* (puntatore a List) */

/* definizione del nodo */
struct Node {
    int value;
    NodePtr next; /* next == NULL se ultimo */
};

/* definizione della lista (senza campo size) */
struct List {
    NodePtr head;
    NodePtr tail;
};

/* ------------------------------------------------------------------
   COMMENTO/CONSEGNA (mettere prima della funzione da implementare)
   ------------------------------------------------------------------

   Funzione richiesta:
     void split_reverse_positions(ListPtr src, ListPtr pari, ListPtr dispari);

   Descrizione (da rispettare nella tua implementazione):
   - Riceve tre parametri: puntatori alle liste:
       src     -> lista sorgente contenente i nodi iniziali (List*)
       pari    -> lista di ritorno che dovrà contenere gli elementi che
                  stavano nelle posizioni 2,4,6,... della sorgente (List*)
       dispari -> lista di ritorno che dovrà contenere gli elementi che
                  stavano nelle posizioni 1,3,5,... della sorgente (List*)
   - La prima posizione della sorgente è considerata posizione 1 (quindi
     è "dispari").
   - Le liste di ritorno devono avere gli elementi in **ordine invertito
     rispetto alla posizione** nella sorgente. Esempio:
         sorgente = [1,2,3,4,5,6]
         pari   = [6,4,2]
         dispari= [5,3,1]
     (l'elemento che stava più a destra nella sorgente tra quelli pari
      diventa il primo nella lista 'pari', e analogo per 'dispari'.)
   Vincoli obbligatori:
   - NON usare malloc/free dentro split_reverse_positions.
   - NON effettuare un primo ciclo che conta il numero di elementi
     della lista sorgente (non fare "prima conto, poi separo").
   - Riassegnare i nodi esistenti (nessun nuovo Node allocato). Alla fine
     la sorgente può essere vuotata.
   - Non aggiungere campo 'size' alla struct List.
   - La funzione deve impostare correttamente head e tail delle liste di
     ritorno (pari e dispari) al termine.
   ------------------------------------------------------------------ */

/* Intestazione della funzione (corpo vuoto - implementare qui) */
void split_reverse_positions(ListPtr src, ListPtr pari, ListPtr dispari) {
    pari->head    = pari->tail    = NULL;
    dispari->head = dispari->tail = NULL;

    NodePtr current = src->head;
    int position = 1;

    while (current != NULL) {
        NodePtr next = current->next;

        ListPtr dest = (position % 2 == 0) ? pari : dispari;

        current->next = dest->head;
        dest->head = current;
        if (dest->tail == NULL)
            dest->tail = current;

        current = next;
        position++;
    }

    src->head = src->tail = NULL;
}

void print_list(ListPtr list) {
    NodePtr current = list->head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main(void) {
    Node nodes[6];
    for (int i = 0; i < 6; i++) {
        nodes[i].value = i + 1;
        nodes[i].next  = (i < 5) ? &nodes[i + 1] : NULL;
    }

    List src     = { &nodes[0], &nodes[5] };
    List pari    = { NULL, NULL };
    List dispari = { NULL, NULL };

    printf("source: ");
    print_list(&src);

    split_reverse_positions(&src, &pari, &dispari);

    printf("even:   ");
    print_list(&pari);

    printf("odd:    ");
    print_list(&dispari);

    return 0;
}