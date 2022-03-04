//
// Created by Daniel on 04.03.2022.
//

#ifndef F1_OPERATIONS_H
#define F1_OPERATIONS_H

#include "scalar.h"
#include "vector.h"
#include "matrix.h"
#include <errno.h>
#include <stdlib.h>

vector_t* scalar_multiply_vector(scalar_t*, vector_t*);
vector_t* add_vectors(vector_t*, vector_t*);
vector_t* reverse_vector(vector_t*);

scalar_t* dot_product(vector_t*, vector_t*);
vector_t* vector_multiply_matrix(vector_t*, matrix_t*);

#endif //F1_OPERATIONS_H