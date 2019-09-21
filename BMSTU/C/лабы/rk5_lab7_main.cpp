#include <stdio.h>

#define N 10

void printMass(int mass[], int size)
{
	int i;
	printf("Array: ");
	for (i = 0; i < size; ++i)
	{
		printf("%d ", mass[i]);
	}
	printf("\n");
}

void rightShift(int mass[], unsigned left, unsigned right)
{
	for (unsigned i = right; i > left; --i)
	{
		mass[i] = mass[i - 1];
	}
}

void rightCircleShift(int mass[], unsigned left, unsigned right)
{
	int temp = mass[right];
	rightShift(mass, left, right);
	mass[left] = temp;
}

int linearSearch(int mass[], int size, int value)
{
	/*int i;
	for (i = 0; i < size; ++i)
	{
		if (mass[i] >= value)
			return i;
	}
	return size;*/

	int i = 0;
	while (i < size && mass[i++] < value);
	return i;
}

int binarySearch(int mass[], int left, int right, int value)
{
	while (right - left >= 0)
	{
		switch (right - left)
		{
			case 0:
				if (mass[left] <= value)
					return left;
				else
					return left + 1;
			default:
				if (mass[left + (right - left) / 2] == value)
					return left + (right - left) / 2;
				else if (value > mass[left + (right - left) / 2])
					left = left + (right - left) / 2 + 1;
				else
					right = left + (right - left) / 2 - 1;
		}
	}
}

int binarySearchRecursive(int mass[], int left, int right, int value)
{
	switch (right - left)
	{
		case 0:
			if (mass[left] <= value)
				return left;
			else
				return left + 1;
		default:
			if (mass[left + (right - left) / 2] == value)
				return left + (right - left) / 2;
			else if (value > mass[left + (right - left) / 2])
				return binarySearchRecursive(mass, left + (right - left) / 2 + 1, right, value);
			else
				return binarySearchRecursive(mass, left, left + (right - left) / 2 - 1, value);
	}
}

void insertSort(int mass[], int size)
{
	int i, insertIndex;
	for (int i = 1; i < size; ++i)
	{
		insertIndex = linearSearch(mass, i, mass[i]);
		if (insertIndex < i)
		{
			rightCircleShift(mass, insertIndex, i);
		}
	}
}

void insertSortRecurse(int mass[], int fullSize, int sortSize)
{
	if (sortSize > fullSize)
		return;

	int insertIndex = linearSearch(mass, sortSize - 1, mass[sortSize - 1]);
	
	if (insertIndex < sortSize - 1)
	{
		rightCircleShift(mass, insertIndex, sortSize - 1);
	}

	insertSortRecurse(mass, fullSize, sortSize + 1);
}

int main()
{
	int mass[N] = { 2, 5, 3, 1, -10, 3, 7, 6, 11, -8 };
	printMass(mass, N);

	rightCircleShift(mass, 1, 4);
	printMass(mass, N);

	insertSort(mass, N);
	printMass(mass, N);

	printf("Position for %d - %d\n", 4, linearSearch(mass, N, 4));
	printf("Position for %d - %d\n", 1, binarySearch(mass, 0, N - 1, 1));
	printf("Position for %d - %d\n", 1, binarySearchRecursive(mass, 0, N - 1, 1));


	getchar();
	return 0;
}