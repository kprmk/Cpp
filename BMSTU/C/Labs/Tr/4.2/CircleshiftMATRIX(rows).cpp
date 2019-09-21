#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5 //rows
#define M 5 // columns

void init(int mas[][M], int n);
void print(int mas[][M], int n);
int randnum(int min, int max);
void leftcircleshiftALL(int mas[][M], int n);
void leftshift(int mas[][M], int n, int index);

int main(void)
{
	int tmas[N][M];
	init(tmas, N);
	print(tmas, N);
	leftcircleshiftALL(tmas, N);
	print(tmas, N);

	getchar();
	return 0;
}

void init(int mas[][M], int n)
{
	srand(time(NULL));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			mas[i][j] = randnum(1, 100);
		}
	}
}

void print(int mas[][M], int n)
{
	putchar('\n');
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			printf(" %3d", mas[i][j]);
		}
		putchar('\n');
	}
}

int randnum(int min, int max)
{
	return min + rand() % (max - min + 1);
}

void leftcircleshiftALL(int mas[][M], int n)
{
	for (int i = 1; i < N; ++i)
	{
		for (int j = i; j > 0; --j)
		{
			leftshift(mas, n, i);
		}
	}
}

void leftshift(int mas[][M], int n, int index)
{
	int a = mas[index][0];
	for (int i = 0; i < M; ++i)
	{
		mas[index][i] = mas[index][i + 1];
	}
	mas[index][M - 1] = a;
}