#pragma once
#include <iostream>
#include "fig3D.h"

class ball : public fig3D
{
protected:
	double r;
public:
	ball(double X = 0, double Y = 0, double Z = 0, double U1 = 0, double U2 = 0, double U3 = 0,
		double R = 0) : fig3D(X, Y, Z, U1, U2, U3), r(R) {}
	~ball() {}

	void print() { std::cout << "x = " << x << "\ny = " << y << "\nz = " << z <<
			"\nu1 = " << u << "\nu2 = " << u2 << "\nu3 = " << u3 << "\nRadius r = " << r
			<< "\nArea = " << area() << "\nVolume = " << volume() << '\n' <<std::endl; }

	double volume() { return 4 / 3 * 3.14 * r * r * r; }
	double area() { return 4 * 3.14 * r * r; }
	double perimeter() { return 0; }
};

