#include <stdio.h>

int euclid_gcd(int a,int b)
{
    while(a != b)
    {
        if(a>b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }

    return a;
}

int main()
{
    int a = 0;
    int b = 0;
    scanf("%d %d",&a,&b);
    int gcd = euclid_gcd(a,b);
    printf("gcd = %d",gcd);
    return 0;
}
