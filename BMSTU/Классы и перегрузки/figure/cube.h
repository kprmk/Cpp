#pragma once
#include <iostream>
#include "fig3D.h"

class cube : public fig3D
{
protected:
	double a;

public:
	cube(double X = 0, double Y = 0, double Z = 0, double U1 = 0, double U2 = 0, double U3 = 0,
		double A = 0) : fig3D(X, Y, Z, U1, U2, U3), a(A) {}
	~cube() {}

	void print() {	std::cout << "x = " << x << "\ny = " << y << "\nz = " << z <<
			"\nu1 = " << u << "\nu2 = " << u2 << "\nu3 = " << u3 << "\nSide a = " << a 
			<< "\nArea = " << area() << "\nPerimeter = " << perimeter()
			<< "\nVolume = " << volume() << '\n' << std::endl;	}

	double volume() { return a * a * a; }
	double area() { return  6 * a * a; }
	double perimeter() { return 12 * a ; }
};

