#include "Circle.hpp"
#include <math.h>

Circle::Circle(double r){
    set_radius(r);
}

Circle::Circle(){
    is_init = false;
}

Circle::~Circle(){
    // do nothing
}

bool Circle::is_initialized(){
    return is_init;
}

void Circle::calc_area(double r){
    area = r*r*M_PI;
}

void Circle::calc_perimeter(double r){
    perimeter = 2*M_PI*r;
}

/*
 *  Setters
 */

void Circle::set_radius(double r){
    radius = r;
    calc_area(r);
    calc_perimeter(r);
    is_init = true;
}

/*
 *  Getters
 */

double Circle::get_side(){
    if(is_initialized()){
        return radius;
    }
    else{
        return -1;
    }
}

double Circle::get_area(){
    if(is_initialized()){
        return area;
    }
    else {
        return -1;
    }
}

double Circle::get_perimeter(){
    if(is_initialized()){
        return perimeter;
    }
    else {
        return -1;
    }
}

void Circle::print_info(){
    if(is_initialized()){
        std::cout << "Circle" << std::endl;
        std::cout << "Radius: " << radius << std::endl;
        std::cout << "Area: " << area << std::endl;
    }
    else{
        std::cout << "circle not initialized" << std::endl;
    }
}

void Circle::reset(){
    is_init = false;
}


