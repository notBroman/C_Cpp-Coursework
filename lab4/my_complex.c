#include "my_complex.h"

struct complex {
    double re;
    double im;
}

Complex addComplex(Complex a, Complex b)
{
    Complex res;

    res.re = a.re + b.re;
    res.im = a.im + b.im;

    return res;
}
/*
Complex mulComplex(Complex a, Complex b)
{
    Complex res;

    res.re = a.re * b.re + a.im * b.im;
    res.im = a.re * b.im + a.im * b.re;

    return res;
}

Complex conjComplex(Complex a)
{
    Complex res;
    res.re = a.re;
    res.im = (-1) * a.im;
}

Complex divComplex(Complex a, Complex b)
{
    Complex res;
    res.re = mul(a, conjComplex(b)).Re/mul(b, conjComplex(b));
    res.im = mul(a, conjComplex(b)).Im/mul(b, conjComplex(b));

    return res;
}
*/
