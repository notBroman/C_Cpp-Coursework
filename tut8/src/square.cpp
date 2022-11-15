#include <time.h>
#include "square.h"


class Square{
    protected:
        double side;
        bool is_init;
        double area;

    public:
        Square(double a){
            input_side(a);
        }

        Square(){
            is_init = false;
            // do nothing
        }

        bool is_Initialized(){
            return is_init;
        }

        double get_side(){
            if(is_Initialized()){
                return side;
            }
            else {
                return -1;
            }
        }

        double get_area(){
            if(is_Initialized()){
                return area;
            }
            else {
                return -1;
            }
        }

        void input_side(double in_side){
            side = in_side;
            area = side*side;

            is_init = true;
        }

        void input_side_from_keyboard(){
            double new_side;
            std::cout << "Please enter dimension of side" << std::endl;
            std::cin >> new_side;

            input_side(new_side);
        }

        void input_random_side(double max_val = 100.0){
           srand(time(NULL));
        }

        void print_Info(){
            if(is_Initialized()){
                std::cout << "Square" << std::endl;
                std::cout << "sides: " << get_side() << std::endl;
                std::cout << "area: " << get_area() << std::endl;
            }
            else {
                std::cout << "square not initialized" << std::endl;
            }
        }

        void reset(){
            is_init = false;
        }
};
