#include "Point.h"

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Point::move(int dx, int dy)
{
	x += dx;
	y += dy;
}

void Point::move(int dx)
{
	x += dx;
}