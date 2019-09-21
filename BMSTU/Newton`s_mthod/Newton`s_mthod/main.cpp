#include <iostream>
#include <cstdlib>
#include <cmath>

using  std::cout;
using  std::endl;

double F1(double x, double y);
double F2(double x, double y);

double dF1dx(double x, double y);
double dF1dy(double x, double y);
double dF2dx(double x, double y);
double dF2dy(double x, double y);
double deff(double x, double y);

double for_x_after_reverse_multi(double x, double y);
double for_y_after_reverse_multi(double x, double y);

int main()
{
	const int e = 1000000;
	int count = 0;
	double x = 0.5, y = 1.5, x_n, y_n, delta;

	cout << "x_0 == " << x << endl << "y_0 == " << y << endl;

	do
	{
		x_n = x - for_x_after_reverse_multi(x,y) / deff(x,y);
		y_n = y - for_y_after_reverse_multi(x,y)/ deff(x,y);

		delta = pow(pow(x_n - x, 2) + pow(y_n - y, 2), 0.5);

		cout << '`' << delta << endl;
		
		x = x_n;
		y = y_n;

		count++;
	} while (delta < e);

	cout << count << endl;

	system("pause");
	return 0;
}

double for_x_after_reverse_multi(double x, double y)
{
	//Expand[(1 + x)*(x ^ 3 + x ^ 3 y ^ 3 + y ^ 3 - 17) - (x + xy + y -
	//	5)*(3 y ^ 2 + 3 x ^ 3 y ^ 2)]

	//	- 17 - 17 x + x ^ 3 + x ^ 4 + 15 y ^ 2 - 3 x y ^ 2 + 15 x ^ 3 y ^ 2 - 3 x ^ 4 y ^ 2 -
	//	3 xy y ^ 2 - 3 x ^ 3 xy y ^ 2 - 2 y ^ 3 + x y ^ 3 - 2 x ^ 3 y ^ 3 +
	//	x ^ 4 y ^ 3  // FullSimplify

	//	- 17 - 17 x + x ^ 3 + x ^ 4 -
	//	3 (1 + x ^ 3) (-5 + x + xy) y ^ 2 + (-2 + x - 2 x ^ 3 + x ^ 4) y ^ 3

	double p = -17 - 17 * x + pow(x, 3) + pow(y, 4) - 3 * (1 + pow(x, 3))*(-5 + x + x * y)*pow(y, 2) +
		(-2 + x - 2 * pow(x, 3) + pow(x, 4))*pow(y, 3);

	return p;
}

double for_y_after_reverse_multi(double x, double y)
{
		// Expand[(-1 - y)*(x ^ 3 + x ^ 3 y ^ 3 + y ^ 3 - 17) + (x + xy + y -
		//5)*(3 x ^ 2 + 3 y ^ 3 x ^ 2)]

		//17 - 15 x ^ 2 + 2 x ^ 3 + 3 x ^ 2 xy + 17 y + 3 x ^ 2 y - x ^ 3 y -
		//y ^ 3 - 15 x ^ 2 y ^ 3 + 2 x ^ 3 y ^ 3 + 3 x ^ 2 xy y ^ 3 - y ^ 4 + 3 x ^ 2 y ^ 4 -
		//x ^ 3 y ^ 4 // FullSimplify

		//-(1 + y) (-17 + y ^ 3) + 3 x ^ 2 (-5 + xy + y) (1 + y ^ 3) -
		//x ^ 3 (-2 + y - 2 y ^ 3 + y ^ 4)

	double q  = (-1 - y)*(-17 + pow(y, 3)) + 3 * pow(x, 2)*(-5 + x * y + y)*(1 + pow(y, 3)) -
		pow(x, 3)*(-2 + y - 2 * pow(y, 3) + pow(y, 4));

	return q;
}

double F1(double x, double y)
{ 
	return pow(x, 3) + pow(x, 3) * pow(y, 3) + pow(y, 3) - 17; 
}

double F2(double x, double y)
{
	return x + y + x * y - 5;
}

double dF1dx(double x, double y)
{
	return 3*pow(x, 2) + 3 * pow(x, 2) * pow(y, 3) ;
}

double dF1dy(double x, double y)
{
	return 3 * pow(y, 2) + 3 * pow(y, 2) * pow(x, 3);
}

double dF2dx(double x, double y)
{
	return 1 + y;
}

double dF2dy(double x, double y)
{
	return 1 + x;
}

double deff(double x, double y)
{
	double w = 3 * (pow(x, 3) + pow(x, 2) + pow(x, 2) * pow(y, 3) - pow(y, 3) - pow(y, 2) - pow(x, 3) * pow(y, 2));
	return w;
}
