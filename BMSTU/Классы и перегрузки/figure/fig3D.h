#pragma once
#include <iostream>
#include "figure.h"

class fig3D: public figure
{
protected:
	double z, u2, u3;

public:
	fig3D(double X = 0, double Y = 0, double Z = 0 , double U1 = 0, double U2 = 0, double U3 = 0) :
	figure( X, Y, U1), z(Z), u2(U2), u3(U3) {}
	~fig3D() {}

	virtual double volume() = 0;
};

