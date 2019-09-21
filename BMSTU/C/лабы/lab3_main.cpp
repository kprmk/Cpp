#include <stdio.h>

int maxCommonDelimiter(int n1, int n2);
int simpleDelimiters(int num);

int main()
{
	//printf("%d\n", maxCommonDelimiter(24, 36));
	printf("Max = %d\n", simpleDelimiters(25));

	getchar();
	return 0;
}

int maxCommonDelimiter(int n1, int n2)
{
	// 1. ���� ����� ������ ������� - ������ �� �������
	if (n1 < n2)
	{
		int temp = n1;
		n1 = n2;
		n2 = temp;
	}

	// 2. ���� ��� �� ��������� �������
	int r = n1 % n2;
	while (r)
	{
		n1 = n2;
		n2 = r;
		r = n1 % n2;
	}

	return n2;
}

int simpleDelimiters(int num)
{
	int del = 2, delNum = 0;

	while (del <= num || del * del <= num)
	{
		if (!(num % del))
		{
			delNum++;
			num /= del;
		}
		else
		{
			if (delNum)
				printf("%d (%d)\n", del, delNum);
			del++;
			delNum = 0;
		}
	}
	printf("%d (%d)\n", del, delNum);

	return del;
}