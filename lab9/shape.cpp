#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Circle.hpp"
#include "shape.hpp"

Shape::Shape() : m_shape_id(++Shape::m_shapes_created){
    Shape::m_shapes_alive++;
    m_coord_init = false;
}

Shape::~Shape(){
    Shape::m_shapes_alive--;
}

/*
 *  static functions & members
 */

int Shape::m_shapes_created = 0;
int Shape::m_shapes_initialized = 0;
int Shape::m_shapes_alive = 0;

void Shape::print_shapes_info(){
    std::cout << "-- Shapes Stats --" << std::endl;
    std::cout << "shapes created: " << Shape::m_shapes_created << std::endl;
    std::cout << "shapes initiailized: " << Shape::m_shapes_initialized << std::endl;
    std::cout << "shapes alive: " << Shape::m_shapes_alive << std::endl << std::endl;
}

/*
 *  input functions for Coord and shape
 */

bool Shape::is_initialized(){
    return m_coord_init;
}

bool Shape::input_side(double side){
    if (!m_shape.is_initialized() && side > 0){
        m_shape.set_radius(side);
        return true;
    }
    else {
        return false;
    }
}

bool Shape::input_coord(double in_X, double in_Y){
    if(!(*this).is_initialized() && in_X > 0 && in_Y > 0){
        m_x = in_X;
        m_y = in_Y;
        return true;
    }
    else {
        return false;
    }
}

bool Shape::input_side_from_keyboard(){
    double a;
    std::cout << "Please input a side length" << std::endl;
    std::cin >> a;
    return Shape::input_side(a);
}

bool Shape::input_random_coord(double max_val){
    srand(time(NULL));
    return Shape::input_coord(drand48()*max_val, drand48()*max_val);
}

/*
 *  getter functions
 */

double Shape::get_area(){
    return m_shape.get_area();
}

double Shape::get_perimeter(){
    return m_shape.get_perimeter();
}

double Shape::get_side(){
    return m_shape.get_side();
}

/*
 *  reset functions
 */

void Shape::reset_shape(){
    m_shape.reset();
}

void Shape::reset_coord(){
    m_coord_init = false;
}




