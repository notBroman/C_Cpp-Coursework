#include <stdio.h>

typedef struct complex{
    double Re;
    double Im;
} complex;

void print_complex(complex z)
{
    printf("%lf, %lf",z.Re,z.Im);
}

complex complex_product(complex z1, complex z2)
{
    complex res;
    res.Re = z1.Re * z2.Re - z1.Im * z2.Im;
    res.Im = z1.Re * z2.Im + z1.Im * z2.Re;

    return res;
}

int main(int argc, char *argv[])
{
    complex a = {1, 2};
    complex b = {1, -2};
    print_copmlex(complex_product(a,b));
    return 0;
}
