#pragma once
#include "fig3D.h"

class pyramid : public fig3D
{
protected:
	double h;

public:
	pyramid(double X = 0, double Y = 0, double Z = 0, double U1 = 0, double U2 = 0, double U3 = 0,
		double H = 0) : fig3D(X, Y, Z, U1, U2, U3), h(H) {}
	~pyramid() {}

};

class trpyramid : public pyramid
{
protected:
	double a, b, c;

public:
	trpyramid(double X = 0, double Y = 0, double Z = 0, double U1 = 0, double U2 = 0, double U3 = 0,
		double H = 0, double A = 0, double B = 0, double C = 0) : pyramid(X,Y,Z,U1,U2,U3,H), a(A), b(B), c(C) {}
	~trpyramid() {}


	void print() {
		std::cout << "x = " << x << "\ny = " << y << "\nz = " << z <<
			"\nu1 = " << u << "\nu2 = " << u2 << "\nu3 = " << u3 << 
			"\nHeight = "<< h << "\nSide a = " 
			<< a << "\nSide b = " << b << "\nSide c = " << c 
			<< "\nArea = " << area() << "\nPerimeter = "<< perimeter() << "\nVolume = " 
			<< volume() << '\n' << std::endl; }

	double area() { return; }
	double perimeter() { return ; }
	double volume() { return; }

};

class recpyramid : public pyramid
{
protected:
	double a, b;

public:
	recpyramid(double X = 0, double Y = 0, double Z = 0, double U1 = 0, double U2 = 0, double U3 = 0,
		double H = 0, double A = 0, double B = 0) : pyramid(X, Y, Z, U1, U2, U3, H), a(A), b(B) {}
	~recpyramid() {}


	void print() {
		std::cout << "x = " << x << "\ny = " << y << "\nz = " << z <<
			"\nu1 = " << u << "\nu2 = " << u2 << "\nu3 = " << u3 <<
			"\nHeight = " << h << "\nSide a = "
			<< a << "\nSide b = " << b << "\nArea = " << area() << 
			"\nPerimeter = " << perimeter() << "\nVolume = "
			<< volume() << '\n' << std::endl;
	}

	double area() { return; }
	double perimeter() { return; }
	double volume() { return; }

};