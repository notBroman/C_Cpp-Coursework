#pragma once

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Circle.hpp"

class Shape{
    protected:
        double m_x;
        double m_y;
        bool m_coord_init;
        Circle m_shape;

        static int m_shapes_created;
        static int m_shapes_initialized;
        static int m_shapes_alive;

        const int m_shape_id;

    public:
        Shape();
        ~Shape();

        static void print_shapes_info();

        /*
         *  input functions
         */

        bool is_initialized();

        bool input_side(double side);

        bool input_coord(double in_X, double in_Y);

        bool input_side_from_keyboard();

        bool input_random_coord(double max_val = 25);

        /*
         *  getter functions
         */

        double get_area();

        double get_perimeter();

        double get_side();

        /*
         *  reset functions
         */

        void reset_shape();

        void reset_coord();
};
