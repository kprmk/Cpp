#pragma once
class figure
{						
private:
	double x, y;
public:
	figure(double X, double Y) { x = X; y = Y; };
	~figure();

	void move (double X, double Y) { x += X; y += Y; };
	virtual double Area() = 0;
};

class rectangle : public figure
{
private:
	double a, b;
public:
	rectangle(double X, double Y, double A, double B) :figure(X, Y), a(A), b(B) {};
	double Area() { return a * b; }
};

class circle : public figure
{
private:
	double z;
public:
	circle(double X, double Y, double Z) : figure(X, Y), z(Z) {};
	double Area() { return 3.14 * z * z; }
};