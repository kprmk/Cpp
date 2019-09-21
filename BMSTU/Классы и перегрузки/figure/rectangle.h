#pragma once
#include"iostream"
#include "figure.h"

class rectangle : public figure
{
protected:
	double a, b;

public:
	rectangle(double X = 0, double Y = 0, double U = 0, double A = 0, double B = 0) : figure(X, Y, U), a(A), b(B) {}
	~rectangle(){}

	void print() { std::cout << "x = " << x << "\ny = " << y << "\nu = " << u <<
		"\nSide a = " << a << "\nSide b = " << b << "\nArea =  " 
		<< area() << "\nPerimeter = " << perimeter() << '\n' << std::endl; }

	double area() { return a * b; }
	double perimeter() { return (a + b) * 2; }
};