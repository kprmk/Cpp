#include <stdio.h>
#include <math.h>

int main()
{
	int inum = 2, i;

	/*for (i = 1; i <= 12; ++i)
	{
		printf("2 ^ %d = %d\n", i, inum);
		inum *= 2;
	}*/

	for (i = 1; i < 7; i++)
	{
		printf("2 ^ %-2d = %-4d\t", i, (int)pow(2, i));
		printf("2 ^ %-2d = %-4d\n", i + 6, (int)pow(2, i + 6));
	}

	getchar();
	return 0;
}

//int a = 4, b = 5, c = 1;

/* 1. Отсортировать стороны треугольника
(переназначить их), вывести длины сторон
на экран в порядке возрастания */
//if (a > b)
//{
//	if (b >= c)
//	{
//		int temp = a;
//		a = c;
//		c = temp;
//	}
//	else
//	{
//		int temp = a;
//		a = b;
//		b = temp;

//		if (b > c)
//		{
//			int temp = b;
//			b = c;
//			c = temp;
//		}
//	}
//}
//else if (a == b)
//{
//	if (a > c)
//	{
//		int temp = a;
//		a = c;
//		c = temp;
//	}
//}
//else
//{
//	if (b > c)
//	{
//		int temp = b;
//		b = c;
//		c = temp;

//		if (a > b)
//		{
//			int temp = a;
//			a = b;
//			b = temp;
//		}
//	}
//}

//printf("Triangle sides:\n");
//printf("a = %d, b = %d, c = %d\n\n", a, b, c);

///* 2. Проверить, можно ли составить 
//	треугольник из таких отрезков, 
//	вывести информацию об этом на экран */
//if (c >= a + b)
//{
//	printf("This is not a triangle :(\n");
//}
//else
//{
//	printf("Oh, this is a triangle! :)\n");

//	/* 3. Определить тип треугольника (остроугольный,
//	тупоугольный, прямоугольный), вывести информацию
//	на экран */
//	if (c * c > a * a + b * b)
//	{
//		printf("Triangle is dummy!\n");
//	}
//	else if (c * c < a * a + b * b)
//	{
//		printf("Triangle is sharp!\n");
//	}
//	else
//	{
//		printf("Triangle is from Manhattan!\n");
//	}

//	/* 4. Проверить, является ли треугольник
//	равносторонним/равнобедренным, вывести информацию
//	на экран */
//	if (a == b && b == c)
//	{
//		printf("Triangle is equal-side!\n");
//	}
//	else
//	{
//		if (a == b || b == c || a == c)
//		{
//			printf("Triangle has 2 equal sides of 3!\n");
//		}
//		else
//		{
//			printf("Triangle is random :D \n");
//		}
//	}
//}