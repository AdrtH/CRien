#include <stdio.h>
#include "./cr_matrix.h"

int main(void)
{
    float val[][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {3.14,2.71,9.81},
    {-69,-420,0.666},
  };

  float val2[3][3] = {
    {2,0,0},
    {0,2,0},
    {0,0,2}
  };
  
  matrix m = create_matrix(5,3,val);
  print_matrix(m);
  printf("===============\n");

  matrix m2 = create_matrix(3,3, val2);
  print_matrix(m2);
  printf("===============\n");
  
  matrix result = matrix_product(m,m2);
  print_matrix(result);
  printf("===============\n");

  matrix m3     = matrix_sum(m2,m2);
  print_matrix(m3);
  printf("===============\n");  


  matrix m4     = matrix_scalar(-8, m);
  print_matrix(m4);
  printf("===============\n");

  matrix m5     = matrix_mult(m, m2);
  print_matrix(m5);
  printf("===============\n");

  float val3[3][3] = {
    {16,12,4},
    {7,4,4},
    {6,7,14}
  };
  matrix m6     = create_matrix(3,3,val3);
  print_matrix(m6);
  printf("===============\n");

  matrix m7     = matrix_mult(m2,m6);
  print_matrix(m7);
  printf("===============\n");

  matrix m8     = matrix_transpose(m);
  print_matrix(m8);
  printf("===============\n");
 
  return 0;
}
