#ifndef CR_LINKEDLIST
#define CR_LINKEDLIST

// Comments in English should be for users of this file,
// Comments in French are for me, explaining something if I ever need to go back and change something
// you are free to try and translate french comments, but if you're not planning to do a contribution, you will waste your time, it's not important

#include <stdlib.h>
#define CR_LINKEDLIST_TYPE int //SAFE TO CHANGE

// WARNING: this can leak memory under certain circumstances,
// However being careful about removing or freeing your list should prevent any leaking.

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

void linkedlist_freeAll(linkedlist_t* ll){
  // Of course this function is dangerous, all your pointers to anything within the list should not be accessed anymore
  // If you want to just free a single element, search for the remove function
  if(ll->next != NULL){
    linkedlist_freeAll(ll->next);
  }
  free(ll);
}

void linkedlist_remove(linkedlist_t* ll, size_t index)
{
  linkedlist_t* next = ll;
  if(index == 0){
    free(next);
    return;
  }
  for(int i=0; i < index-1 && next->next != NULL; ++i){ // on va chercher le ultieme element avant l'index à retirer (pour changer son .next essentiellement)
    next = next->next;
  }
  linkedlist_t* tofree = next->next;	    // ce node ne doit plus exister apres remove
  next->next	       = next->next->next;  // on change l'element suivant par celui d'apres
  free(tofree);
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
