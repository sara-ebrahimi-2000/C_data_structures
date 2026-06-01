#include <stdio.h>
#include <stdlib.h>
typedef struct listnode ListNode,
*ListNodeptr;

struct listnode{
  void* data;
  ListNodeptr next;
};

struct charstack{
    ListNodeptr top;
    int size;
};

typedef struct charstack *charstackADT;

charstackADT mkstack(){
  charstackADT s = malloc(sizeof(*s));
  if(s == NULL) return NULL;
  
  s->top = NULL;
  s->size = 0;
  
  return s;
  
}


// is Emty return NUll
_Bool isEmty(charstackADT s){
  return (s->size == 0);
}

_Bool push(charstackADT s,void *e){
  ListNodeptr ptr = malloc(sizeof(*ptr));
  if(ptr == NULL) return 0;
  
  ptr->data = e;
  
  ptr->next = s->top;
  s->top = ptr;
  
  return 1;
}
void *pop(charstackADT s){
  if(isEmty(s)){ return NULL; }
  
  void *e = s->top->data;
  ListNodeptr ptr = s->top;
  s->top = s->top->next;
  
  free(ptr);
  s->size--;
  
  return e;
}
_Bool dsStack(charstackADT *s){
   
   
   ListNodeptr ptr = (*s)->top;
   
   
   while(ptr != NULL){
     ListNodeptr temp = ptr;
     ptr= ptr->next;
     free(temp);
   }
   
   free(*s);
   *s = NULL;
}


int main() {
  charstackADT s = mkstack();
  int a = 12;
  int b = 13;
  char c = 'A';
  
  
  push(s,&a);
  push(s,&b);
  push(s,&c);
  dsStack(&s);
  
  return 0;
}
