#ifndef F1_MATRIX_H
#define F1_MATRIX_H

typedef struct {
    int rows;
    int cols;
    double** values;
} matrix_t;

matrix_t* init_matrix(unsigned, unsigned);
unsigned get_rows(matrix_t*);
unsigned get_cols(matrix_t*);
double get_matrix_value_at(matrix_t*, unsigned, unsigned);
void set_matrix_value_at(matrix_t*, unsigned, unsigned, double);
void destroy_matrix(matrix_t*);

#endif //F1_MATRIX_H
