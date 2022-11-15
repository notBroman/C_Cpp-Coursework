#include <math.h>
#include "roots.h"

#define TOL 0.0001

double sq_root(double real)
{
    double x = 0.0; //x_k+1
    double xp = 1.0; //x_k
    x = xp/2 + real/(2*xp); //compute new value for x

    while(fabs(x - xp) > TOL)
    {
        xp = x; //set to previous iteration of x_k+1
        x = xp/2 + real/(2*xp); //compute new value for x
    }
    return x;
}

double n_root(double a, double n)
{
    /*
     *  Using Newton's Method
     */

    double x = 0.0;
    double xp =1.0;
    x = ((n-1)/n)*xp + (a/(n*pow(xp,n-1)));

    while(fabs(x - xp) > TOL)
    {
        xp = x;
        x = ((n-1)/n)*xp + (a/(n*pow(xp,n-1)));
    }
    return x;
}
