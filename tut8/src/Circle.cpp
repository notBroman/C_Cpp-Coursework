#include "Circle.cpp"

class Circle{
    protected:
        double radius;
        double area;
        bool is_init;

    public:
        Circle(double r){
            radius = r;
            area = r*r*std::numbers.pi
            is_init = true;
        }

        Circle(){
            is_init = false;
        }

        bool is_initialized(){
            return is_init;
        }

        void print_info(){
            if(is_initialized()){
                std::cout << "Circle" << std:endl;
                std::cout << "Radius: " << radius << std::endl;
                std::cout << "Area: " << area << std::endl;
            }
            else{
                std::cout << "circle not initialized" << std::endl;
            }
        }
};
