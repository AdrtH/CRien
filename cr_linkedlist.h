#ifndef CR_LINKEDLIST
#define CR_LINKEDLIST

#include <stdlib.h>
#define CR_LINKEDLIST_TYPE int //SAFE TO CHANGE


typedef struct linkedlist_t {
  CR_LINKEDLIST_TYPE	val;
  struct linkedlist_t*	next;
} linkedlist_t;

linkedlist_t *find_end(linkedlist_t *ll){
  linkedlist_t* next = ll;
  while(next->next != NULL){
    next = next->next;
  }
  return next;
}

void linkedlist_append(linkedlist_t* ll, CR_LINKEDLIST_TYPE val)
{
  linkedlist_t* tail = find_end(ll);
  linkedlist_t* new  = malloc(sizeof(linkedlist_t));
  tail->next	     = new;
  *new		     = (linkedlist_t){val,NULL};
  return;
}


void array_to_linkedlist(size_t len, CR_LINKEDLIST_TYPE arr[len], linkedlist_t* ll){
  *ll = (linkedlist_t){*arr, NULL};
  for(int i=1; i<len; ++i){
    linkedlist_append(ll, arr[i]);
  }
}

void linkedlist_pretty_print(linkedlist_t ll){
  linkedlist_t* next = &ll;
  while(next->next != NULL){
    printf("%d->",next->val);
    next = next->next;
  }
    printf("%d\n",next->val);
}

#endif //CR_LINKEDLIST
