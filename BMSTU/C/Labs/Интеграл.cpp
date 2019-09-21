#include <stdio.h>
#include <math.h>

double f(double x);
unsigned rectangle(double* pS, double a, double b, double eps, double(*pf)(double));
unsigned trap(double* pS, double a, double b, double eps, double(*pf)(double));
unsigned simpson(double* pS, double a, double b, double eps, double(*pf)(double));

int main()
{
	const double pi = 3.1415926535897932384626433832795;
	double S;
	unsigned n;


	//n = trap(&S, 0, pi, 1e-8, sin);
	n = trap(&S, 0, 1, 1e-8, f);
	//n = rectangle(&S, 0, 1, 1e-8, f);
	//n = rectangle(&S, 0, pi, 1e-8, sin);
	//n = simpson(&S, 0, 1, 1e-8, f);

	printf("=======================================\n");
	printf("n = %-12u S = %18.15f\n", n, S);

	getchar();
	return 0;
}

double f(double x)
{
	return x*x;
}

unsigned rectangle(double* pS, double a, double b, double eps, double(*pf)(double))
{
	double S, S_prev, h, h_prev, Sum;
	unsigned n, i;

	n = (unsigned)sqrt((b - a) / sqrt(eps));
	if (n < 2) n = 2;

	Sum = 0.;
	h = (b - a) / n;
	for (i = 0; i < n; i++)
		Sum += pf(a + i*h);
	S = Sum*h;

	do
	{
		h_prev = h;
		h = h / 2.;
		S_prev = S;
		Sum = 0.;

		for (i = 0; i < n; i++)
			Sum += pf(a + i*h_prev + h);

		S = (S_prev / 2.) + (Sum * h);
		n *= 2.;

		printf("n = %-12u S = %18.15f\n", n, S);
	} while (fabs(S - S_prev)>eps);

	*pS = S;
	return n;
}

unsigned trap(double* pS, double a, double b, double eps, double(*pf)(double))
{
	double S, S_prev, h, h_prev, Sum;
	unsigned n, i;

	n = (unsigned)sqrt((b - a) / sqrt(eps));
	if (n < 2) n = 2;

	Sum = (pf(a) + pf(b)) / 2.;
	h = (b - a) / n;
	for (i = 1; i < n; i++)
		Sum += pf(a + i*h);
	S = Sum * h;

	do
	{
		h_prev = h;
		h = h / 2.;
		S_prev = S;
		Sum = 0.;

		for (i = 0; i < n; i++)
			Sum += pf(a + i*h_prev + h);

		S = (S_prev / 2.) + (Sum * h);
		n *= 2.;

		printf("n = %-12u S = %18.15f\n", n, S);
	} while (fabs(S - S_prev)>eps);

	*pS = S;
	return n;

}

unsigned simpson(double* pS, double a, double b, double eps, double(*pf)(double))
{
	double S, S_prev, h, h_2, Sum_outside, Sum_inside, Sum_fa_fb;
	unsigned n, i;

	n = (unsigned)sqrt((b - a) / sqrt(eps));
	if (n < 2) n = 2;


	h = (b - a) / n;
	h_2 = h / 2.;
	Sum_fa_fb = pf(a) + pf(b);
	Sum_outside = 0.;
	Sum_inside = pf(a + h_2);
	for (i = 1; i < n; i++)
	{
		Sum_outside += pf(a + i*h);
		Sum_inside += pf(a + i*h + h_2);
	}
	S = (Sum_fa_fb + 2 * Sum_outside + 4 * Sum_inside) * h / 6.;

	do
	{
		h = h / 2.;
		h_2 = h / 2.;
		n *= 2.;
		S_prev = S;
		Sum_outside += Sum_inside;
		Sum_inside = 0.;

		for (i = 0; i < n; i++)
			Sum_inside += pf(a + i*h + h_2);

		S = (Sum_fa_fb + 2 * Sum_outside + 4 * Sum_inside) * h / 6.;

		printf("n = %-12u S = %18.15f\n", n, S);
	} while (fabs(S - S_prev)>eps);

	*pS = S;
	return n;
