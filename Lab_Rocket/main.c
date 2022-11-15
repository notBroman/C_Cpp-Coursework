#include <stdio.h>
#include <math.h>

#define INIT_FUEL 5000.0
#define INIT_WEIGHT 1000.0
#define INIT_ALT 100000.0
#define GRAV 1.620
#define VR 400
#define dt 10

int main()
{
    double altitude = INIT_ALT;
    double weight = INIT_WEIGHT;
    double t = 0;
    double v = 0;
    double mk = 0;
    double aval_fuel = INIT_FUEL;
    double v_impact = 0;

    printf("\nPlanet Landing\n");
    printf("--------------------------------------------\n");
    printf("Initial fuel: %.0lf\n", INIT_FUEL);
    printf("Rocket weight: %.0lf\n",INIT_WEIGHT);
    printf("Initial altitude: %.0lf\n", INIT_ALT);
    printf("Planet Gravity: %.6lf\n", GRAV);
    printf("--------------------------------------------\n\n");

    printf("time\taltitube[m]\tfuel[kg]\tspeed[m/s]\n");


    while(altitude >0 && aval_fuel > 0)
    {

        printf("% 4.0lf\t% 11.0lf\t% 8.0lf\t% 10.3lf\t\tburn fuel[kg]:",t,altitude,aval_fuel,v);
        scanf("%lf",&mk);
        // update parameters
        t += dt;
        altitude = altitude + (v * dt);
        v = v - (GRAV * dt) + (VR * mk)/(aval_fuel + INIT_WEIGHT);
        aval_fuel -= mk;

        printf("\r\n");
        mk = 0;

    }
    printf("fuel ran out at %.0lfm\n",altitude);
    if (aval_fuel == 0 && altitude > 0)
    {
        v_impact = -1 * fabs(v) + sqrt((v*v) + (2 * GRAV * altitude));
    }
    else
    {
        v_impact = v;
    }

    printf("impact velocity: %lf",v_impact);
    return 0;
}
