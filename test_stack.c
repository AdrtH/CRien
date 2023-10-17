#include <stdio.h>
#include "./cr_stack.h"

int main(void)
{
  cr_stack su = {0};
  push(&su, 5);
  push(&su, 3);
  push(&su, 1);
  push(&su, 2);
  push(&su, 4);
  push(&su, 7);


  int stop = su.count;
  for(int i = 0; i < stop; i++) {
    printf("%d\n",peek_stack(&su));
    printf("%d\n",pop(&su));
  }

  return 0;
}
