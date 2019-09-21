#include <stdio.h>

int main() 
{
	int a = 3, b = 4, c = 5;

	/* 1. ������� ������� ������������ �� ��������
		� ������� �������������� ���������� */
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

	/* 2. ���������, ���������� �� �����������
		� ������ ���������, ������� ���������� 
		�� ���� �� ����� */
	if (a >= b + c)
		printf("This is not a triangle!\n");
	else
	{
		printf("Oh, that's a triangle!\n\n");

	/* 3. ��������� ��� ������������ (�������������,
		������������, �������������) � �������
		���������� �� ����� */
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

	/* 4. ���������, �������� �� �����������
		��������������/��������������, �������
		���������� �� ����� */
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