#pragma once
#include <iostream>
#include "rectangle.h"

class square: public rectangle
{
public:
	square(double X = 0, double Y = 0, double U = 0, double A = 0) : rectangle(X, Y, U, A) {}
	~square() {}

	void print() {	std::cout << "x = " << x << "\ny = " << y << "\nu = " << u <<
			"\nSide = " << a << "\nArea =  " << area() << "\nPerimeter = "
		<< perimeter() << '\n' << std::endl; }

	double area() { return a * a; }
	double perimeter() { return a * 4; }
};

