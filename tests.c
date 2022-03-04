#include "utils.h"
#include "tests.h"
#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include "scalar.h"
#include "vector.h"
#include "matrix.h"
#include "operations.h"

void run_scalar_tests();
void run_vector_tests();
void run_matrix_tests();
void run_operations_tests();

void run_all_tests() {
    printf("Running all tests\n");
    run_scalar_tests();
    run_vector_tests();
    run_matrix_tests();
    run_operations_tests();
}



void run_scalar_tests() {
    double value = 1.2;
    scalar_t* scalar = init_scalar(value);



// fprintf(stderr, "value = %lf; scalar.value = %lf\n", value, get_value(&scalar));
    assert(eq_double(value, get_value(scalar)));
    destroy_scalar(scalar);
}



void run_vector_tests() {
    vector_t* vector = init_vector(3);
    assert(get_size(vector) == 3);
    set_value_at(vector, 0, 0.0);
    set_value_at(vector, 1, 1.0);
    set_value_at(vector, 2, 2.0);



    assert(eq_double(get_value_at(vector, 0), 0.0));
    assert(eq_double(get_value_at(vector, 1), 1.0));
    assert(eq_double(get_value_at(vector, 2), 2.0));

    get_value_at(vector, 3);
    assert(errno==-1);
    errno = 0;

    set_value_at(vector, 4, 0.5);
    assert(errno==-1);
    errno = 0;
    destroy_vector(vector);
}

void run_matrix_tests(){
    matrix_t* matrix = init_matrix(2, 2);
    assert(get_rows(matrix)==2);
    assert(get_cols(matrix)==2);
    set_matrix_value_at(matrix, 0, 0, 3.0);
    assert(eq_double(get_matrix_value_at(matrix, 0, 0), 3));
    get_matrix_value_at(matrix, 3, 3);
    assert(errno==-1);
    errno = 0;
    set_matrix_value_at(matrix, 4, 3, 0.7);
    assert(errno==-1);
    errno = 0;
    destroy_matrix(matrix);
}

void run_operations_tests(){
    scalar_t* scalar = init_scalar(7);
    vector_t* vector = init_vector(2);
    set_value_at(vector, 0, 3);
    set_value_at(vector, 1, 4);

    vector_t* s_vector = scalar_multiply_vector(scalar, vector);
    assert(eq_size_vectors(s_vector, vector)==0);
    assert(eq_double(get_value_at(s_vector, 0), 21));
    assert(eq_double(get_value_at(s_vector, 1), 28));

    vector_t* sum_vector = add_vectors(vector, s_vector);
    assert(eq_size_vectors(sum_vector, vector)==0);
    assert(eq_double(get_value_at(sum_vector, 0), 24));
    assert(eq_double(get_value_at(sum_vector, 1), 32));
    destroy_vector(sum_vector);

    vector_t* d3_vector = init_vector(3);
    sum_vector = add_vectors(vector, d3_vector);
    assert(errno==-2);
    assert(sum_vector==NULL);
    errno=0;

    vector_t* rev_vector = reverse_vector(vector);
    sum_vector = add_vectors(rev_vector, vector);
    assert(eq_double(get_value_at(sum_vector, 0), 0));
    assert(eq_double(get_value_at(sum_vector, 1), 0));

    destroy_scalar(scalar);
    scalar = dot_product(vector, rev_vector);
    assert(eq_double(get_value(scalar), -25));

    matrix_t* rot_matrix = init_matrix(2, 2);
    set_matrix_value_at(rot_matrix, 0, 0, 0);
    set_matrix_value_at(rot_matrix, 0, 1, 1);
    set_matrix_value_at(rot_matrix, 1, 0, -1);
    set_matrix_value_at(rot_matrix, 1, 1, 0);
    vector_t* prod_vector = vector_multiply_matrix(vector, rot_matrix);
    assert(get_size(vector) == get_cols(rot_matrix));
    assert(eq_double(get_value_at(prod_vector, 0), -4));
    assert(eq_double(get_value_at(prod_vector, 1), 3));

    destroy_vector(prod_vector);
    prod_vector = vector_multiply_matrix(d3_vector, rot_matrix);
    assert(errno==-3);
    assert(prod_vector==NULL);
    errno = 0;

    destroy_scalar(scalar);
    destroy_vector(vector);
    destroy_vector(s_vector);
    destroy_vector(sum_vector);
    destroy_vector(d3_vector);
    destroy_vector(rev_vector);
}