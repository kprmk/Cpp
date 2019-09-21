#pragma once
#include <iostream>
#include "point.h"
#include "line.h"

class poly : public line
 {
private:
	point a, b, c;

public:
	poly(point A, point B, point C)/*a(A), b(B) , c(C)*/ { a = A; b = B; c = C; }
	poly(double A, double B, double C, double D, double E, double F) : a(A, B), b(B, C), c(E, F) {}
	~poly() {}

	point fttt(const double t)
	{
		double t2 = t * t;
		point x = a * t2 + b * t + c;
		std::cout <<  "ft  "<< x.getx() << std::endl;
		std::cout << "ft  " << x.gety() << std::endl;

		return x;
	}

};

