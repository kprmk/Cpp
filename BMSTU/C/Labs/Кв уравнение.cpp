#include <stdio.h>

double f(double x);		//
double modul(double x);	//

int main()
{
	double a = 1., b = 3., c; // �����, ������ ������� � ����� ���������� ����� � ��� �
	double eps_x = 1e-12;     // �������� ������� ����� ��� �
	unsigned n = 0;           // ������� ��������

	if ((a < b) && f(a) * f(b) < 0) // �������� ������������ ������� ������
	{
		do
		{
			c = a - f(a)*(b - a) / (f(b) - f(a)); // ������ ���������� ����������� ������ ��� �
			if (f(a) * f(c) < 0)
				if (b - c < eps_x)  // ��������, ��� ����� ������ ������� ����������� ���������� �� ���������� 
					break;
				else
					b = c;
			else
				if (c - a < eps_x)  // ��������, ��� ����� ����� ������� ����������� ���������� �� ���������� 
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
double f(double x)      // ����������� �������. ������ ���� ������������ �� ��������� [a, b].
{
	return x * x - 2;
}
double modul(double x)  // ������� ������� ������
{
	return (x < 0 ? -x : x);
}
