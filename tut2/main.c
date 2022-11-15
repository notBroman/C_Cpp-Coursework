#include <stdio.h>
#include "roots.h"


int main()
{
    double a = 0;
    double b = 0;
    double n = 0;
    printf("please input a number to find the sqrt of: ");
    scanf("%lf",&a);
    double approx = sq_root(a);
    printf("The sqrt of %lf is: %lf\n\n",a,approx);

    printf("input base and degree of root\n");
    scanf("%lf %lf",&b,&n);
    double approx_1 = n_root(b,n);
    printf("the %.1lf-th root of %lf is: %lf",n,b,approx_1);

    return 0;
}
