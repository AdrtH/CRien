#include <stdio.h>
#include "./cr_queue.h"


int main(void)
{

  queue q = {0};
  enqueue(&q, 5);
  enqueue(&q, 3);
  enqueue(&q, 2);
  enqueue(&q, 1);
  enqueue(&q, 4);
  enqueue(&q, 7);

  int stop = length_queue(&q);
  for(int i = 0; i < stop; i++) {
    printf("iteration %d\n",i);
    printf("%zu\n",length_queue(&q));
    printf("%d\n",peek_queue(&q));
    printf("%d\n",dequeue(&q));
  }

  // to test if the sort of garbage collection thingy works (spoiler it does)(change the capacity to five)
  enqueue(&q, 1);
  enqueue(&q, 1);
  enqueue(&q, 1);
  enqueue(&q, 1);
  enqueue(&q, 1);
  
  stop = length_queue(&q);
  for(int i = 0; i < stop; i++) {
    printf("iteration %d\n",i);
    printf("%zu\n",length_queue(&q));
    printf("%d\n",peek_queue(&q));
    printf("%d\n",dequeue(&q));
  }

  
  return 0;
}
