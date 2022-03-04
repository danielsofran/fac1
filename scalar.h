#pragma once
typedef struct {
double value;
} scalar_t;



scalar_t* init_scalar(double);
double get_value(scalar_t*);
void destroy_scalar(scalar_t*);