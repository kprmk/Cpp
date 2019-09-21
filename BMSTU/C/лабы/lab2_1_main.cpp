#include <stdio.h>

int main() 
{
	int a = 3, b = 4, c = 5;

	/* 1. Вывести стороны треугольника по убыванию
		с помощью переназначения переменных */
	if (a < b)
	{
		if (b <= c)
		{
			int temp = a;
			a = c;
			c = temp;
		}
		else
		{
			int temp = a;
			a = b;
			b = temp;

			if (b < c)
			{
				int temp = b;
				b = c;
				c = temp;
			}
		}
	}
	else if (a > b)
	{
		if (b < c)
		{
			int temp = b;
			b = c;
			c = temp;

			if (a < b)
			{
				int temp = a;
				a = b;
				b = temp;
			}
		}
	}
	else
	{
		if (a < c)
		{
			int temp = a;
			a = c;
			c = temp;
		}
	}

	printf("Sides: a = %d, b = %d, c = %d\n\n", a, b, c);

	/* 2. Проверить, существует ли треугольник
		с такими сторонами, вывести информацию 
		об этом на экран */
	if (a >= b + c)
		printf("This is not a triangle!\n");
	else
	{
		printf("Oh, that's a triangle!\n\n");

	/* 3. Проверить вид треугольника (остроугольный,
		тупоугольный, прямоугольный) и вывести
		информацию на экран */
		if (a * a < b * b + c * c)
		{
			printf("Trinangle is sharp... :)\n");
		}
		else if (a * a > b * b + c * c)
		{
			printf("Triangle is dummy... :D\n");
		}
		else
		{
			printf("Triangle is Manhattan-styled... :)\n");
		}

	/* 4. Проверить, является ли треугольник
		равносторонним/равнобедренным, вывести
		информацию на экран */
		if (a == b && b == c)
		{
			printf("... and has all sides equal!\n");
		}
		else
		{
			if (a == b || b == c || a == c)
			{
				printf("... and has 2 sides equal of 3!\n");
			}
			else
			{
				printf("... and is pretty!\n");
			}
		}
	}

	getchar();
	return 0;
}