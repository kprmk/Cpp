#pragma once
#include "figure.h"

class triangle : public figure
{
protected:
	double a, b, c;

public:

	triangle(double X = 0, double Y = 0, double U = 0 ,double A = 0, double B = 0, double C = 0): figure(X, Y, U), a(A), b(B), c(C) {}
	~triangle(){}

	void print() { std::cout << "x = " << x << "\ny = " << y << "\nu = " << u <<
			"\nSide a = " << a << "\nSide b = " << b << "\nSide c = " << c << "\nArea =  "
			<< area() << "\nPerimeter = " << perimeter() << '\n' << std::endl; }

	double area() 
	{ 
		double p = (a + b + c) / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}

	double perimeter()
	{
		return a + b + c;
	}
};

