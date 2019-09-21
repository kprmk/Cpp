//#define _USE_MATH_DEFINES 
//#include <cmath>
#pragma once
#include <iostream>
#include "figure.h"

class ellipse : public figure
{
//private:
protected:
	double q, p;

public:
	/*double get_q() { return q; }
	double get_p() { return p; }*/

	ellipse(double A = 0, double B = 0, double U = 0, double Q = 0, double P = 0) : figure(A, B, U), q(Q), p(P) {}
	~ellipse() {};

	void print() { std::cout << "x = " << x << "\ny = " << y << "\nu = " << u <<
			"\nAxis a = " << q << "\nAxis b = " << p << "\nArea =  "
			<< area() << "\nPerimeter = " << perimeter() << '\n' << std::endl; }

	double area() { return 3.14 * q * p; }
	double perimeter() { return (4 * 3.14 * q * p +  4 * (q - p)) / (q + p); }

};

