#ifndef CR_ITERWINDOW
#define CR_ITERWINDOW

// To explain what this is, I found out that I needed a type of iterator which was going through a window of integer, starting from x ending at y, and I needed this window to "slide"

#include <stdlib.h>
#define CR_WINDOWITER_TYPE int // SAFE TO CHANGE

typedef struct windowiter_t {
  CR_WINDOWITER_TYPE*		   start;
  size_t			   length;
  const CR_WINDOWITER_TYPE *       init_start;
  const size_t                     length_arr;
} windowiter_t;

windowiter_t windowiter_init(size_t length, CR_WINDOWITER_TYPE arr[length], size_t win_length)
{
  // should definitely use this to create a window
  return (windowiter_t){arr, win_length, arr, length};
}

void windowiter_next(windowiter_t *windowiter, size_t step){
  if(step + windowiter->start + windowiter->length > windowiter->init_start + windowiter->length_arr) {
    printf("ERROR: Overstepping window at address: %p\n", windowiter);
    exit(1);
  }
  windowiter->start = (step+windowiter->start);
}

CR_WINDOWITER_TYPE *windowiter_get(windowiter_t *windowiter)
{
  CR_WINDOWITER_TYPE* ret = malloc(sizeof(*ret)*windowiter->length);
  for(int i = 0; i < (int)windowiter->length; ++i){
    *(ret+i) = *(windowiter->start +i);
  }
  return ret;
}


#endif //CR_ITERWINDOW
