#ifndef RectangleExample_h
#define RectangleExample_h

#include <iostream>
using namespace std;

// rand, srand
#include <stdlib.h>

class rectangle{
protected:
	// static member variable used for count
	//static int object_count;

	// variables
	double sideA, sideB;
	double area;
	double perimeter;

	// initialization flag
	bool init_flag;

	// functions
	void computeArea()
	{
		if(isInitialized())
			area=sideA*sideB;
	}
	void computePerimeter()
	{
		if(isInitialized())
			perimeter=2*(sideA+sideB);
	}

public:
	// constructor
	rectangle()
	{
		// basic initialization
		init_flag=false;
	}

	// gets

	double getArea()
	{
		if(isInitialized())
			return area;
		else
			cout << "Error in getArea(): Rectangle is not initialized " << endl;
		return 0;
	}
	double getPerimeter()
	{
		if(isInitialized())
			return perimeter;
		else
			cout << "Error in getPerimeter(): Rectangle is not initialized " << endl;
		return 0;
	}
	bool isInitialized(){return init_flag;}
	double getSide(int sidenum)
	{
		double out;
		if(isInitialized())
		{

			switch(sidenum){
			case 1:
				out=sideA;
				break;
			case 2:
				out=sideB;
				break;
			default:
				cout << "Error in getSide(): Incorrect sidenum value" << endl;
				out=-1;
			}
		}
		else
		{
			cout << "Error in getSide(): Rectangle is not initialized" << endl;
			out=-1;
		}
		return out;
	}
	void inputSides(double in_sideA, double in_sideB)
	{
		if(!isInitialized())
		{
			if(in_sideA>0 && in_sideB>0)
			{
				sideA=in_sideA;
				sideB=in_sideB;
				init_flag=true;
				computeArea();
				computePerimeter();
			}
			else
				cout << "Error in inputSides(): Incorrect input values" << endl;
		}
		else
			cout << "Error in inputSides(): Rectangle is already initialized " << endl;

	}
	void inputSidesFromKeyboard()
	{
		if(!isInitialized())
		{
			double in_sideA, in_sideB;

			cout << "Please enter dimension of side A of the Rectangle (then hit ENTER)" << endl;
			cin >> in_sideA;

			cout << "Please enter dimension of side B of the Rectangle (then hit ENTER)" << endl;
			cin >> in_sideB;

			inputSides(in_sideA, in_sideB);
		}
		else
			cout << "Error in inputSidesFromKeyboard(): Rectangle is already initialized " << endl;
	}
	void printRectangleInfo()
	{
		if(isInitialized())
		{
			cout << "Rectangle side A is: " << getSide(1) << endl;
			cout << "Rectangle side B is: " << getSide(2) << endl;
			cout << "Rectangle area is: " << getArea() << endl;
			cout << "Rectangle perimeter is: " << getPerimeter() << endl;
		}
		else
			cout << "printRectangleInfo(): Rectangle dimensions not initialized " << endl;
	}
	void inputRandomSides(double max_val=100)
	{
		if(!isInitialized())
		{
			double in_sideA, in_sideB;
			int rand_valueA=0;
			int rand_valueB=0;

			// check that max_val is a meaningful value
			if(max_val<=0)
				max_val=100;

			// this produces a random integer within (0 , RAND_MAX]
			while(rand_valueA==0)
				rand_valueA=rand();
			while(rand_valueB==0)
				rand_valueB=rand();
			// this produces a random double within (0 , max_val]
			in_sideA=( ((double)rand_valueA)/(RAND_MAX) )*max_val;
			in_sideB=( ((double)rand_valueB)/(RAND_MAX) )*max_val;
			inputSides(in_sideA, in_sideB);
		}
		else
			cout << "Error in inputRandomSides(): Rectangle is already initialized " << endl;
	}
};



#endif
