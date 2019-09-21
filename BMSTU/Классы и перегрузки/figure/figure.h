#pragma once
#include<iostream>

class figure
{
protected:
	double x, y, u;
public:
	double get_x(){ return x; }
	double get_y(){ return y; }
	double get_u1(){ return u; }

	void printk(){  std::cout << "x = "<< x << "\ny = " << y << "\nu = " << u << '\n' << std::endl; }

	figure(double X = 0, double Y = 0, double A = 0) { x = X; y = Y; u = A; }
	virtual ~figure() {}

	void move(double X, double Y) { x += X; y += Y; };
	void rotate(double A) { u += A; };
	void replace(double X, double Y, double U) { x += X; y += Y; u += U; };

	virtual void print() = 0;
	virtual double area() = 0;
	virtual double perimeter() = 0;
};