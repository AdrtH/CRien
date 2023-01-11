#ifndef CR_STACK
#define CR_STACK


#include <stdlib.h>
#define CR_MAX_STACK_CAP 64000 //SAFE TO CHANGE but that should be enough for everyone 


typedef struct stack_t{
  void*		items[CR_MAX_STACK_CAP];
  size_t	count;
} cr_stack;


// add an element to the stack
void push(cr_stack *s, void* val)
{
  if(s->count == CR_MAX_STACK_CAP){
    printf("ERROR: Overflowing stack at address: %p\n",s);
    exit(1);
  }
  s->items[s->count] = val;
  (s->count)++;
}

// return the element on top then removes it from the stack
// WARNING: the element is not strictly removes the count is just decremented,
// so any pointers or for loop with a weird value can access that
void* pop(cr_stack *s)
{
  if(s->count == 0){
    printf("ERROR: Underflowing stack at address: %p\n",s);
    exit(1);
  }
  (s->count)--;
  void* ret = s->items[s->count];
  return ret;
}

// work just as if you pop then push the result
void* peek_stack(cr_stack *s)
{
  if((s->count) -1 < 0){
    printf("ERROR: Underpeeking stack at address: %p\n",s);
    exit(1);
  }
  return s->items[(s->count) -1];
}


#endif //CR_STACK
