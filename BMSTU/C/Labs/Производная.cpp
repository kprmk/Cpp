#include "stdafx.h"
#include <stdio.h>
#include <math.h>

double f(double x);
double df_dx(double x);   // Производная функции

unsigned newton(double* px, double eps_x, double eps_f, double(*pf)(double x), double(*pdf_dx)(double x));
unsigned cut(double* px, double eps_x, double eps_f, double(*pf)(double x));

int main()
{
	double x = 3.;        // Начальное приближение
	double eps_x = 1e-12; // Погрешность аргумента (вдоль оси X)
	double eps_f = 1e-12; // Погрешность значения функции (вдоль оси Y)
	unsigned n = 0;       // Счётчик числа итераций

						  //n = newton(&x, eps_x, eps_f,f,df_dx);
						  //n = newton(&x, eps_x, eps_f, sin, cos);
	n = cut(&x, eps_x, eps_f, sin);
	printf("n = %u\n", n);
	printf("x = %18.15f\n", x);

	getchar();
	return 0;
}

double f(double x)
{
	return x * x * x - 2;
}

double df_dx(double x)
{
	return 3 * x * x;
}

unsigned newton(double* px, double eps_x, double eps_f, double(*pf)(double x), double(*pdf_dx)(double x))
{
	double x = *px;
	double x0;            // Предыдущее приближение
	unsigned n = 0;       // Счётчик числа итераций

	do
	{
		x0 = x;
		x = x - pf(x) / pdf_dx(x);
		n++;
		printf("n = %u\tx = %18.15f\tf(x) = %18.15f\n", n, x, pf(x));
	} while (fabs(x - x0) > eps_x && fabs(pf(x)) > eps_f);

	*px = x;
	return n;
}

unsigned cut(double* px, double eps_x, double eps_f, double(*pf)(double x))
{
	double x = *px;
	double x0;            // Предыдущее приближение
	unsigned n = 0;       // Счётчик числа итераций
	double tangent, h;

	do
	{
		x0 = x;
		h = fabs(pf(x));
		tangent = (pf(x + h) - pf(x - h)) / (2 * h);
		x = x - pf(x) / tangent;
		n++;
		printf("n = %u\tx = %18.15f\tf(x) = %18.15f\n", n, x, pf(x));
	} while (fabs(x - x0) > eps_x && fabs(pf(x)) > eps_f);

	*px = x;
	return n;
}
