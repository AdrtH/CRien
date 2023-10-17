#include <stdio.h>
#include "./cr_iterwindow.h"

int main(void)
{
  int arr[10]	   = {5,2,1,4,5,6,3,2,7,8};
  windowiter_t win = windowiter_init(10, arr, 3);
  windowiter_next(&win, 5);
  
  int* test        = windowiter_get(&win);
  for(int i=0; i<3; ++i){
    printf("%d\n", *(test+i));
  }
  
  return 0;
}
