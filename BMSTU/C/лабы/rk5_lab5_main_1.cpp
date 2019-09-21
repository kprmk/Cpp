#include <stdio.h>

#define NN 10

void swap(int *pa, int *pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void printMass(int mass[], int size)
{
	int i;

	printf("Massiv: ");
	for (i = 0; i < size; ++i)
	{
		printf("%d ", mass[i]);
	}
	printf("\n");
}

int minElement(int mass[], int size)
{
	int i, minIndex = 0;

	for (i = 1; i < size; ++i)
	{
		if (mass[i] < mass[minIndex])
		{
			minIndex = i;
		}
	}

	return minIndex;
}

int maxElement(int mass[], int N)
{
	int i, maxIndex = 0;

	for (i = 1; i < N; ++i)
	{
		if (mass[i] > mass[maxIndex])
		{
			maxIndex = i;
		}
	}

	return maxIndex;
}

void bubbleSort(int mass[], int N)
{
	int i, j, swapDone = 0;
	for (i = N - 1; i > 1; --i)
	{
		for (j = 0; j < i; ++j)
		{
			if (mass[j] > mass[j + 1])
			{
				swap(mass + j, mass + j + 1);
				swapDone = 1;
			}
		}

		if (!swapDone)
			break;
		else
			swapDone = 0;
	}
}

int main()
{
	int mass[NN] = { 2, -5, 3, 4, 0, 9, 18, 25, 7, 2 };
	printMass(mass, NN);

	bubbleSort(mass, NN);
	printMass(mass, NN);

	int min = minElement(mass, NN);
	int max = maxElement(mass, NN);
	printf("Min = %d (index = %d), ", mass[min], min);
	printf("Max = %d (index = %d)\n", mass[max], max);

	getchar();
	return 0;
}