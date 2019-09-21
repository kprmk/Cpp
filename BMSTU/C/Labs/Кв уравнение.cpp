#include <stdio.h>

double f(double x);		//
double modul(double x);	//

int main()
{
	double a = 1., b = 3., c; // Левая, правая границы и точка пересечния хорды и оси Х
	double eps_x = 1e-12;     // Точность решения вдоль оси Х
	unsigned n = 0;           // Счетчик итераций

	if ((a < b) && f(a) * f(b) < 0) // Проверка корректности входных данных
	{
		do
		{
			c = a - f(a)*(b - a) / (f(b) - f(a)); // Расчет координаты пересечения хордой оси Х
			if (f(a) * f(c) < 0)
				if (b - c < eps_x)  // Проверка, что новая правая граница существенно отличается от предыдущей 
					break;
				else
					b = c;
			else
				if (c - a < eps_x)  // Проверка, что новая левая граница существенно отличается от предыдущей 
					break;
				else
					a = c;
			n++;
		} while (true);
		printf("n = %d\tx = %18.15f\n", n, c);
	}
	else
		printf("Wrong interval\n");
	getchar();
	return 0;
}
double f(double x)      // Определение функции. Должна быть унимодальной на интервале [a, b].
{
	return x * x - 2;
}
double modul(double x)  // Функция расчета модуля
{
	return (x < 0 ? -x : x);
}
