#include <iostream>
#include "line.h"
#include "point.h"
#include "poly.h"
//double abs(double a, double b);
//double distance(double p1, double  p2, double  p3, double  p4);

using namespace std;

int main()
{
	cout << "qwerty\n\n" << endl;

	line * pa;
	poly p(1, 1, 1, 1, 1, 1);
	pa = &p;
	double a = pa->length(1,2);
	cout << a << endl;

	getchar();
	return 0;
}

//
//double distance(double p1, double  p2, double  p3, double  p4)
//{
//	double x = abs(p1, p2);
//	double y = abs(p3, p4);
//	return sqrt(x * x + y * y);
//}
//
//double abs(double a, double b)
//{
//	//    a    and b  > 0 !
//	double z;
//	z = a - b;
//	if (z > 0)
//		return z;
//
//	else
//		return -z;
//}