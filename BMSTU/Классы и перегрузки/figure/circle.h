//#define _USE_MATH_DEFINES
//#include<cmath>
#pragma once
#include "ellipse.h"

class circle : public ellipse
{
	//using ellipse :: <get_q>; 
	//using ellipse :: <get_p>;

public:
	circle(double X = 0, double Y = 0, double U = 0, double Z = 0) : ellipse(X, Y, U, Z){}
	~circle(){}

	void print() { std::cout << "x = " << x << "\ny = " << y << "\nu = " << u <<
			"\nRadius a = " << q << "\nArea =  " << area() << "\nPerimeter = " << 
			perimeter() << '\n' << std::endl; }

	double area() { return 3.14 * q * q; }
	double perimeter() { return 2 * 3.14 * q * q; }
};