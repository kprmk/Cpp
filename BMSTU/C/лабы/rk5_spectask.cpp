#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 4
#define N 3

int randomNum(int min, int max)
{
	return min + rand() % (max - min + 1);
}

void matrixRandomInitStatic(int mass[][N], int sizeM)
{
	srand(time(NULL));

	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			mass[i][j] = randomNum(-5, 5);
		}
	}
}

void lollyPopPrintLUStr(int mass[][N], int sizeM)
{
	int left = 0, right = N - 1, top = 0, bottom = sizeM - 1;

	while(1)
	{
		unsigned key = 0;

		for (int i = left; i <= right; ++i)
		{
			if (i == left)
				++key;

			printf(" %d", mass[top][i]);
		}
		++top;

		for (int i = top; i <= bottom; ++i)
		{
			if (key == 0)
				break;

			if (i == top)
				++key;

			printf(" %d", mass[i][right]);
		}
		--right;

		for (int i = right; i >= left; --i)
		{
			if (key < 2)
				break;

			if (i == right)
				++key;

			printf(" %d", mass[bottom][i]);
		}
		--bottom;

		for (int i = bottom; i >= top; --i)
		{
			if (key < 3)
				break;

			if (i == bottom)
				++key;

			printf(" %d", mass[i][left]);
		}
		++left;

		if (key < 4)
			break;
	}
}

void lollyPopPrintLDStr(int mass[][N], int sizeM)
{
	int left = 0, right = N - 1, top = 0, bottom = sizeM - 1;

	while (1)
	{
		unsigned key = 0;

		for (int i = bottom; i >= top; --i)
		{
			if (i == bottom)
				++key;

			printf(" %d", mass[i][left]);
		}
		++left;

		for (int i = left; i <= right; ++i)
		{
			if (key == 0)
				break;

			if (i == left)
				++key;

			printf(" %d", mass[top][i]);
		}
		++top;

		for (int i = top; i <= bottom; ++i)
		{
			if (key < 2)
				break;

			if (i == top)
				++key;

			printf(" %d", mass[i][right]);
		}
		--right;

		for (int i = right; i >= left; --i)
		{
			if (key < 3)
				break;

			if (i == right)
				++key;

			printf(" %d", mass[bottom][i]);
		}
		--bottom;

		if (key < 4)
			break;
	}
}

void lollyPopPrintRUStr(int mass[][N], int sizeM)
{
	int left = 0, right = N - 1, top = 0, bottom = sizeM - 1;

	while (1)
	{
		unsigned key = 0;

		for (int i = top; i <= bottom; ++i)
		{
			if (i == top)
				++key;

			printf(" %d", mass[i][right]);
		}
		--right;

		for (int i = right; i >= left; --i)
		{
			if (key == 0)
				break;

			if (i == right)
				++key;

			printf(" %d", mass[bottom][i]);
		}
		--bottom;
		
		for (int i = bottom; i >= top; --i)
		{
			if (key < 2)
				break;

			if (i == bottom)
				++key;

			printf(" %d", mass[i][left]);
		}
		++left;

		for (int i = left; i <= right; ++i)
		{
			if (key < 3)
				break;

			if (i == left)
				++key;

			printf(" %d", mass[top][i]);
		}
		++top;

		if (key < 4)
			break;
	}
}

void lollyPopPrintRDStr(int mass[][N], int sizeM)
{
	int left = 0, right = N - 1, top = 0, bottom = sizeM - 1;

	while (left <= right && top <= bottom)
	{
		unsigned key = 0;

		for (int i = right; i >= left; --i)
		{
			if (i == right)
				++key;

			printf(" %d", mass[bottom][i]);
		}
		--bottom;

		for (int i = bottom; i >= top; --i)
		{
			if (key == 0)
				break;

			if (i == bottom)
				++key;

			printf(" %d", mass[i][left]);
		}
		++left;

		for (int i = left; i <= right; ++i)
		{
			if (key < 2)
				break;

			if (i == left)
				++key;

			printf(" %d", mass[top][i]);
		}
		++top;

		for (int i = top; i <= bottom; ++i)
		{
			if (key < 3)
				break;

			if (i == top)
				++key;

			printf(" %d", mass[i][right]);
		}
		--right;

		if (key < 4)
			break;
	}
}

void lollyPopPrintLURev(int mass[][N], int sizeM)
{
	int left = 0, right = N - 1, top = 0, bottom = sizeM - 1;

	while (left <= right && top <= bottom)
	{
		unsigned key = 0;

		for (int i = top; i <= bottom; ++i)
		{
			if (i == top)
				++key;

			printf(" %d", mass[i][left]);
		}
		++left;

		for (int i = left; i <= right; ++i)
		{
			if (key == 0)
				break;

			if (i == left)
				++key;

			printf(" %d", mass[bottom][i]);
		}
		--bottom;

		for (int i = bottom; i >= top; --i)
		{
			if (key < 2)
				break;

			if (i == bottom)
				++key;

			printf(" %d", mass[i][right]);
		}
		--right;

		for (int i = right; i >= left; --i)
		{
			if (key < 3)
				break;

			printf(" %d", mass[top][i]);
		}
		++top;
	}
}

void lollyPopPrintLDRev(int mass[][N], int sizeM)
{
	int left = 0, right = N - 1, top = 0, bottom = sizeM - 1;

	while (left <= right && top <= bottom)
	{
		unsigned key = 0;

		for (int i = left; i <= right; ++i)
		{
			if (i == left)
				++key;

			printf(" %d", mass[bottom][i]);
		}
		--bottom;

		for (int i = bottom; i >= top; --i)
		{
			if (key == 0)
				break;

			if (i == bottom)
				++key;

			printf(" %d", mass[i][right]);
		}
		--right;

		for (int i = right; i >= left; --i)
		{
			if (key < 2)
				break;

			if (i == right)
				++key;

			printf(" %d", mass[top][i]);
		}
		++top;

		for (int i = top; i <= bottom; ++i)
		{
			if (key < 3)
				break;

			printf(" %d", mass[i][left]);
		}
		++left;
	}
}

void lollyPopPrintRURev(int mass[][N], int sizeM)
{
	int left = 0, right = N - 1, top = 0, bottom = sizeM - 1;

	while (left <= right && top <= bottom)
	{
		unsigned key = 0;

		for (int i = right; i >= left; --i)
		{
			if (i == right)
				++key;

			printf(" %d", mass[top][i]);
		}
		++top;

		for (int i = top; i <= bottom; ++i)
		{
			if (key == 0)
				break;

			if (i == top)
				++key;

			printf(" %d", mass[i][left]);
		}
		++left;

		for (int i = left; i <= right; ++i)
		{
			if (key < 2)
				break;

			if (i == left)
				++key;

			printf(" %d", mass[bottom][i]);
		}
		--bottom;

		for (int i = bottom; i >= top; --i)
		{
			if (key < 3)
				break;

			printf(" %d", mass[i][right]);
		}
		--right;
	}
}

void lollyPopPrintRDRev(int mass[][N], int sizeM)
{
	int left = 0, right = N - 1, top = 0, bottom = sizeM - 1;

	while (left <= right && top <= bottom)
	{
		unsigned key = 0;

		for (int i = bottom; i >= top; --i)
		{
			if (i == bottom)
				++key;

			printf(" %d", mass[i][right]);
		}
		--right;

		for (int i = right; i >= left; --i)
		{
			if (key == 0)
				break;

			if (i == right)
				++key;

			printf(" %d", mass[top][i]);
		}
		++top;

		for (int i = top; i <= bottom; ++i)
		{
			if (key < 2)
				break;

			if (i == top)
				++key;

			printf(" %d", mass[i][left]);
		}
		++left;

		for (int i = left; i <= right; ++i)
		{
			if (key < 3)
				break;

			printf(" %d", mass[bottom][i]);
		}
		--bottom;
	}
}

void printMatrixStatic(int mass[][N], int sizeM)
{
	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%3d ", mass[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int m[M][N];
	
	matrixRandomInitStatic(m, M);
	printMatrixStatic(m, M);

	printf("\nMatrix -> straight lollypop from left upper corner:\n");
	lollyPopPrintLUStr(m, M);
	printf("\nMatrix -> straight lollypop from left down corner:\n");
	lollyPopPrintLDStr(m, M);
	printf("\nMatrix -> straight lollypop from right upper corner:\n");
	lollyPopPrintRUStr(m, M);
	printf("\nMatrix -> straight lollypop from right upper corner:\n");
	lollyPopPrintRDStr(m, M);

	printf("\nMatrix -> reverse lollypop from left upper corner:\n");
	lollyPopPrintLURev(m, M);
	printf("\nMatrix -> reverse lollypop from left down corner:\n");
	lollyPopPrintLDRev(m, M);
	printf("\nMatrix -> reverse lollypop from right upper corner:\n");
	lollyPopPrintRURev(m, M);
	printf("\nMatrix -> reverse lollypop from right upper corner:\n");
	lollyPopPrintRDRev(m, M);

	getchar();
	return 0;
}