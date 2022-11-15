#pragma once

#include "my_complex.c"

struct complex;
typedef struct complex Complex;

Complex addComplex(Complex a, Complex b);

Complex mulComplex(Complex a, Complex b);

Complex conjComplex(Complex a);

Complex divComplex(Complex a, Complex b);

void printComplex(Complex a);
