#include "operations.h"

vector_t* scalar_multiply_vector(scalar_t* scalar, vector_t* vector){
    vector_t* rez = init_vector(get_size(vector));
    for(int i=0;i<rez->size;++i)
        set_value_at(rez, i, get_value_at(vector, i)* get_value(scalar));
    return rez;
}
vector_t* add_vectors(vector_t* first, vector_t* second){
    if(eq_size_vectors(first, second)) {
        errno = -2;
        return NULL;
    }
    vector_t* rez = init_vector(get_size(first));
    for(int i=0;i< get_size(rez);++i)
        set_value_at(rez, i, get_value_at(first, i) + get_value_at(second, i));
    return rez;
}
vector_t* reverse_vector(vector_t* vector){
    vector_t* rez = init_vector(get_size(vector));
    for(int i=0;i< get_size(rez);++i)
        set_value_at(rez, i, -get_value_at(vector, i));
    return rez;
}

scalar_t* dot_product(vector_t* first, vector_t* second){
    if(eq_size_vectors(first, second))
    {
        errno = -2;
        return NULL;
    }
    double sum = 0;
    for(int i=0;i< get_size(first);++i)
        sum+= get_value_at(first, i)* get_value_at(second, i);
    scalar_t* rez = init_scalar(sum);
    return rez;
}

vector_t* vector_multiply_matrix(vector_t* vector, matrix_t* matrix){
    if(get_size(vector) != get_cols(matrix))
    {
        errno = -3;
        return NULL;
    }
    vector_t* rez = init_vector(get_size(vector));
    for(int j=0;j< get_size(rez);++j) // parcurg coloanele
    {
        double sum = 0;
        for(int i=0;i< get_size(rez);++i)
            sum += get_matrix_value_at(matrix, i, j) * get_value_at(vector, i);
        set_value_at(rez, j, sum);
    }
    return rez;
}