#include "utils.h"
#include <math.h>

int eq_double(double a, double b){
    static const double EPS = 1e-5;
    return fabs(a - b) <= EPS;
}