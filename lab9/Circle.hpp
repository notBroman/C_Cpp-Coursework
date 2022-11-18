#pragma once

#include <iostream>
#include <stdlib.h>
#include <math.h>

class Circle{
    protected:
        double radius;
        double area;
        double perimeter;

        bool is_init;

    public:
        Circle();
        Circle(double r);
        ~Circle();

        bool is_initialized();

        void calc_area(double r);

        void calc_perimeter(double r);

        void set_radius(double r);

        double get_side();

        double get_area();

        double get_perimeter();

        void print_info();

        void reset();
};
