#pragma once
#include <stdbool.h>

typedef struct {
    double* values;
    unsigned size;
} vector_t;



vector_t* init_vector(unsigned);
unsigned get_size(vector_t*);
double get_value_at(vector_t*, unsigned);
/*
* Function that returns the value at a given position in the underlying array.
* Input: vector_t*: the vector entity
* unsigned: the position of the desired value
* Output: if 0 <= unsigned < vector_t->size -> vector_t->values[unsigned]
* else errno is set to -1
*/
void set_value_at(vector_t*, unsigned, double);
/*
* Function that sets the value at a given position in the underlying array.
* Input: vector_t*: the vector entity
* unsigned: the position of the set value
* double: the new value to be set
* Output: if 0 <= unsigned < vector_t->size vector_t->values[unsigned] = double
* else errno is set to -1
*/
int eq_size_vectors(vector_t*, vector_t*);
bool eq_vectors(vector_t*, vector_t*);

void destroy_vector(vector_t*);