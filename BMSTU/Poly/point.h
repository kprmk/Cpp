#pragma once
#include <iostream>
#include <cmath>

class point
{
private:
	double x, y;

public:
	point() {}
	point(double X, double Y) { x = X; y = Y; }
	point(point &a)
	{
		this->x = a.x;
		this->y = a.y;
	}
	~point() {}

	double getx() { return x; }
	double gety() { return y; }

	friend double distat(point &p1, point &p2);

	point operator +=(const point &a)
	{
		this->x += a.x;
		this->y += a.y;

		return *this;
	}

	point operator +(const point &a)
	{
		point n;
		n.x = this->x + a.x;
		n.y = this->y + a.y;

		return n;
	}

	point operator *(const double a)
	{
		this->x *= a;
		this->y *= a;

		return *this;
	}

	point operator =(const point &a)
	{
		this->x = a.x;
		this->y = a.y;

		return *this;
	}

	
};

double abs(double a, double b);

double distat(point &p1, point &p2)
{
	double x = abs(p1.getx(), p2.getx());
	double y = abs(p1.gety(), p2.gety());

	//std::cout << x << std::endl;
	//std::cout << y << std::endl;

	return sqrt(x * x + y * y);
}

double abs(double a, double b)
{
	//    a    and b  > 0 !
	double z;
	z = a - b;
	if (z > 0)
		return z;

	else
		return -z;
}



