#include <stdlib.h>
#include <errno.h>
#include "matrix.h"

matrix_t* init_matrix(unsigned rows, unsigned cols){
    matrix_t* matrix = (matrix_t*)malloc(sizeof(matrix_t));
    matrix->values = (double**) malloc(sizeof(double*)*rows);
    for(int i=0;i<rows;++i)
        matrix->values[i] = (double *) malloc(sizeof(double )*cols);
    matrix->rows = rows;
    matrix->cols = cols;
    return matrix;
}

unsigned get_rows(matrix_t* matrix){
    return matrix->rows;
}

unsigned get_cols(matrix_t* matrix){
    return matrix->cols;
}

double get_matrix_value_at(matrix_t* matrix, unsigned row, unsigned col){
    if(row<matrix->rows && col<matrix->cols && row>=0 && col >=0)
        return matrix->values[row][col];
    errno = -1;
    return -1.0;
}

void set_matrix_value_at(matrix_t* matrix, unsigned row, unsigned col, double value){
    if(row<matrix->rows && col<matrix->cols && row>=0 && col >=0)
        matrix->values[row][col] = value;
    errno = -1;
}

void destroy_matrix(matrix_t* matrix){
    for(int i=0;i<matrix->rows;++i)
        free(matrix->values[i]);
    free(matrix->values);
    free(matrix);
}
