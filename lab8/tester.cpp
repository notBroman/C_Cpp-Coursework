
#include "RectangleExample.h"
#include "RightTriangleExample.h"
#include "Polygon_w_color.h"

#include <time.h>


void Part_1(right_triangle obj_array[], int arraysize)
{
     // TO BE COMPLETED BY STUDENT
     // interate over array
     //     user inputs data for every item
     //     print data that was input for element

    for(int i = 0; i<arraysize; i++)
    {
        cout << "input the sides of the triangle" << endl;
        // obj_array[i].inputSidesFromKeyboard();
        obj_array[i].inputRandomSides();

        obj_array[i].printTriangleInfo();
    }
}

void Part_2(right_triangle obj_array[], int arraysize)
{
	// TO BE COMPLETED BY STUDENTS
    // find smallest area of triangle
    // does not account for negative side length
    int idx_min = 0;
    for(int i = 0; i < arraysize; i++)
    {
        if(idx_min != i && obj_array[i].getArea() < obj_array[idx_min].getArea()){
            idx_min = i;
        }
    }
    obj_array[idx_min].printTriangleInfo();
}

void Part_4(double min_area, polygonColorOptions pcolr_target)
{
    int max_elements = 100;
    int j = 0;
	right_triangleWcolor array_1[max_elements];
    right_triangleWcolor array_2[max_elements];

    for( int i = 0; i < max_elements; i++){
        array_1[i].InputRandomValues();
        if(array_1[i].getColor() == pcolr_target){
            array_2[j] = array_1[i];
            j++;
        }
    }
}

int main(int argc, char** argv)
{
	// these are N instantiations (objects) of the class rectangle
	// i.e. variables of the user-defined type "rectangle"
	const int arraysize=10;
	right_triangle obj_array[arraysize];

	// Part 1:
	// The content of "obj_array" can be changed by the following function;
	// the content of "arraysize" will not. Why? (It has nothing to do with "arraysize" being "const".)
	Part_1(obj_array, arraysize);

	// Part 2:
	Part_2(obj_array, arraysize);


	// Part 3:
	right_triangleWcolor test_object;


	// Part 4:
	double min_area=30;
	polygonColorOptions pcolr_target=orange;
	Part_4(min_area, pcolr_target);


	char final[10];
	cout << " Press any key then Enter to finish ";
	cin >> final;

	return 0;
}
