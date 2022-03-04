cmake_minimum_required(VERSION 3.7.2)
project(f1 C)

set(CMAKE_C_STANDARD 99)

set(Sources main.c scalar.c tests.c vector.c utils.c matrix.c operations.c)
set(Headers scalar.h tests.h vector.h utils.h matrix.h operations.h)
add_executable(f1 ${Sources} ${Headers})
