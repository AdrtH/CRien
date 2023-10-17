#ifndef CR_MATRIX
#define CR_MATRIX
// TODO? : This should be its own project, it might become really bloated

// TODOOO : function for identity matrix, square O matrix
// TODOO  : function to "extract" a column/line vector
// TODO   : opérations élémentaires
// TODOO  : Go toward LU factorisation
// TODO   : determinant, inverse

#include <stdlib.h>

typedef struct matrix_t {
  int     lin, col;
  float **val;         // you should not get the data out yourself, but do what you want
} matrix;


matrix create_matrix(int lin, int col, float val[lin][col])
{
  matrix ret = {0};
  ret.col = col;
  ret.lin = lin;
  ret.val = malloc(sizeof(float*)*lin);
  if(!ret.val) {
    printf("ERROR: Can't allocate matrix");
    exit(-1);
  }
  for(int i=0;i<lin; ++i){
    ret.val[i] = malloc(sizeof(float)*col);
    if(!ret.val[i]) {
      printf("ERROR: Can't allocate matrix");
      exit(-1);
    }
    for(int j=0;j<col;++j){
      ret.val[i][j] = val[i][j];
    }
  }
  return ret;
}


void print_matrix(matrix m)
{
  if(m.val == NULL) {
    printf("[]\n");
    return;
  }
  for(int i=0;i<m.lin; ++i){
    printf("[");
    for(int j=0;j<m.col;++j){
      printf("%f", m.val[i][j]);
      if(j<m.col-1) printf(",");
    }
    printf("]\n");
  }
}

int isSquare(matrix m) // return 0 if false, 1 if true
{
  return (m.col == m.lin);
}

float matrix_get(matrix m, int lin, int col) // yes, it will crash your program if your not careful
{
  if(m.lin <= lin || m.col <= col) {
    printf("ERROR: Tried to access non-valid coord of matrix");
    exit(1);
  }
  return m.val[lin][col];
}

void matrix_set(matrix m, int lin, int col, float val)
{
  if(m.lin <= lin || m.col <= col) {
    printf("ERROR: Tried to access non-valid coord of matrix");
    exit(1);
  }  
  m.val[lin][col] = val;
}


// THIS IS NOT THE MATRIX PRODUCT USED EVERYWHERE IT'S THE PRODUCT OF TWO MATRIX OF SAME SIZE,
// !!!! NOT THE "DOT" PRODUCT OF TWO MATRIX !!!!
matrix matrix_mult(matrix m1, matrix m2)
{
  if(m1.lin != m2.lin || m1.col != m2.col) return(matrix){0};
  float ret[m1.lin][m1.col];
  for(int i=0; i<m1.lin; ++i) {
    for(int j=0; j<m1.col; ++j) {
      ret[i][j] = m1.val[i][j]* m2.val[i][j];
    }
  }
  return create_matrix(m1.lin, m2.col, ret);
}

matrix matrix_sum(matrix m1, matrix m2)
{
  if(m1.lin != m2.lin
  || m1.col != m2.col) {
    return (matrix){0};
  }
  float val[m1.lin][m2.lin];
  for(int i=0; i<m1.lin; ++i){
    for(int j=0; j<m1.col; ++j){
      val[i][j] = m1.val[i][j] + m2.val[i][j];
    }
  }
  return create_matrix(m1.lin, m1.col, val);
}

matrix matrix_scalar(int scal, matrix m)
{
  float val[m.lin][m.col];
  for(int i=0; i<m.lin; ++i){
    for(int j=0; j<m.col; ++j){
      val[i][j] = scal*m.val[i][j];
    }
  }
  return create_matrix(m.lin, m.col, val);
}

matrix matrix_product(matrix m1, matrix m2)
{
  if(m1.col != m2.lin){
    return (matrix){0}; // if the matrices dont have a product, it returns the "null" matrix
  }
  float val[m1.lin][m2.col];
  float sum;
  for(int i=0; i<m1.lin; ++i){
    for(int j=0; j<m2.col; ++j){
      sum = 0;
      for(int k=0; k<m1.col; ++k){
	sum += m1.val[i][k] * m2.val[k][j];
      }
      val[i][j] = sum;
    }
  }
  return create_matrix(m1.lin, m2.col, val);
}

void matrix_dimensions(matrix m, int* lin, int* col)
{
  *lin = m.lin; *col = m.col;
  return;
}

matrix matrix_transpose(matrix m)
{
  int lin,col;
  matrix_dimensions(m, &lin, &col);
  float array[col][lin];
  for(int i=0; i<lin; ++i) {
    for(int j=0; j<col; ++j) {
      array[j][i] = m.val[i][j];
    }
  }
  return create_matrix(col, lin, array);
}

#endif // CR_MATRIX
