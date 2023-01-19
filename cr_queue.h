#ifndef CR_QUEUE
#define CR_QUEUE

#include <stdlib.h>
#include <string.h>
#define CR_MAX_QUEUE_CAP 64000 // SAFE TO CHANGE but that should be enough for everyone
#define CR_QUEUE_TYPE int

typedef struct queue_t{
  CR_QUEUE_TYPE items[CR_MAX_QUEUE_CAP];
  size_t	front;
  size_t	rear;
}queue;

size_t length_queue(queue* q)
{
  return (size_t) (q->rear) - (q->front);
}

void shift_queue(queue* q)
{
  size_t length = length_queue(q);
  for(size_t i = 0; i < length; ++i){
    q->items[i] = q->items[i+q->front];
  }
  q->rear  = length;
  q->front = 0;
}

void enqueue(queue* q, CR_QUEUE_TYPE n)
{

  if(q->rear == CR_MAX_QUEUE_CAP  && q->front ==0){
    printf("ERROR: Overflowing queue at address: %p\n",q);
    exit(1);
  }
  if(q->rear == CR_MAX_QUEUE_CAP) {
    shift_queue(q);
  }

  q->items[q->rear] = n;
  (q->rear)++;
}

CR_QUEUE_TYPE dequeue(queue* q)
{
  if(length_queue(q) == 0){
    printf("ERROR: Underflowing queue at address: %p\n",q);
    exit(1);
  }
  CR_QUEUE_TYPE ret = q->items[q->front];
  (q->front)++;
  return ret;
}

CR_QUEUE_TYPE peek_queue(queue* q)
{
  if(length_queue(q) <= 0){
    printf("ERROR: Underpeeking queue at address: %p\n",q);
    exit(1);
  }
  CR_QUEUE_TYPE ret = q->items[q->front];
  return ret;
}

#endif // CR_QUEUE
