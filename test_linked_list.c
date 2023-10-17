#include <stdio.h>
#include "./cr_linkedlist.h"

int main(void)
{

  int arr[]	   = {5,2,1,4,5,6,3,2,7,8};
  linkedlist_t* ll = malloc(sizeof(linkedlist_t));
  array_to_linkedlist(10, arr, ll);
  linkedlist_remove(ll, 3);
  linkedlist_pretty_print(*ll);
  linkedlist_freeAll(ll);
  linkedlist_pretty_print(*ll);


  return 0;
}
