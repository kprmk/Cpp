#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 2
#define N 3

int** matrixMemoryAllocation(int **mass, int sizeM, int sizeN)
{
	mass = (int**)malloc(sizeM * sizeof(int*));
	for (int i = 0; i < sizeM; ++i)
	{
		mass[i] = (int*)malloc(sizeN * sizeof(int));
	}

	return mass;
}

int* matrixMemoryAllocationSingle(int *mass, int sizeM, int sizeN)
{
	mass = (int*)malloc(sizeM * sizeN * sizeof(int));
	return mass;
}

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

void matrixRandomInitDynamic(int **mass, int sizeM, int sizeN)
{
	srand(time(NULL));

	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = 0; j < sizeN; ++j)
		{
			mass[i][j] = randomNum(-10, 10);
		}
	}
}

void matrixRandomInitSingle(int *mass, int sizeM, int sizeN)
{
	srand(time(NULL));

	for (int i = 0; i < sizeM * sizeN; ++i)
	{
		mass[i] = randomNum(-10, 10);
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

void printMatrixDynamic(int **mass, int sizeM, int sizeN)
{
	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = 0; j < sizeN; ++j)
		{
			printf("%3d ", mass[i][j]);
		}
		printf("\n");
	}
}

void printMatrixDynamicSingle(int *mass, int sizeM, int sizeN)
{
	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = 0; j < sizeN; ++j)
		{
			printf("%3d ", mass[i * sizeN + j]);
		}
		printf("\n");
	}
}

void swap(void *pa, void *pb, unsigned size)
{
	void *temp = malloc(size);
	memcpy(temp, pa, size);
	memcpy(pa, pb, size);
	memcpy(pb, temp, size);
	free(temp);
}

void swapInt(int *pa, int *pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;

	//swap(pa, pb, sizeof(int));
}

void swapIntPointer(int **pa, int **pb)
{
	int *temp = *pa;
	*pa = *pb;
	*pb = temp;

	//swap(pa, pb, sizeof(int*));
}

void swapColumnsInStaticMatrix(int mass[][N], int sizeM, int col1, int col2)
{
	if (col1 < 0 || col1 > N || col2 < 0 || col2 > N)
	{
		printf("Error: incorrect index(es) of swappig columns.");
		return;
	}

	for (unsigned i = 0; i < sizeM; ++i)
	{
		swapInt(*(mass + i) + col1, *(mass + i) + col2);
		//swapInt(&(mass[i][col1]), &(mass[i][col2]));
	}
}

void swapColumnsInDynamicMatrix(int **mass, int sizeM, int sizeN, int col1, int col2)
{
	if (col1 < 0 || col1 > sizeN || col2 < 0 || col2 > sizeN)
	{
		printf("Error: incorrect index(es) of swappig columns.");
		return;
	}

	for (unsigned i = 0; i < sizeM; ++i)
	{
		swapInt(*(mass + i) + col1, *(mass + i) + col2);
		//swapInt(&(mass[i][col1]), &(mass[i][col2]));
	}
}

void swapColumnsInDynamicSingleMatrix(int *mass, int sizeM, int sizeN, int col1, int col2)
{
	if (col1 < 0 || col1 > sizeN || col2 < 0 || col2 > sizeN)
	{
		printf("Error: incorrect index(es) of swappig columns.");
		return;
	}

	for (unsigned i = 0; i < sizeM; ++i)
	{
		swapInt(mass + i * sizeN + col1, mass + i * sizeN + col2);
		//swapInt(&(mass[i * sizeN + col1]), &(mass[i * sizeN + col2]));
	}
}

void swapRowsInStaticMatrix(int mass[][N], int sizeM, int row1, int row2)
{
	if (row1 < 0 || row1 > sizeM || row2 < 0 || row2 > sizeM)
	{
		printf("Error: incorrect index(es) of swappig rows.");
		return;
	}

	for (unsigned j = 0; j < N; ++j)
	{
		swapInt(*(mass + row1) + j, *(mass + row2) + j);
		//swapInt(&(mass[row1][j]), &(mass[row2][j]));
	}
}

void swapRowsInDynamicMatrix(int **mass, int sizeM, int sizeN, int row1, int row2)
{
	if (row1 < 0 || row1 > sizeM || row2 < 0 || row2 > sizeM)
	{
		printf("Error: incorrect index(es) of swappig rows.");
		return;
	}

	for (unsigned j = 0; j < N; ++j)
	{
		swapInt(*(mass + row1) + j, *(mass + row2) + j);
		//swapInt(&(mass[row1][j]), &(mass[row2][j]));
	}

	//swapIntPointer(mass + row1, mass + row2);
}

void swapRowsInDynamicSingleMatrix(int *mass, int sizeM, int sizeN, int row1, int row2)
{
	if (row1 < 0 || row1 > sizeM || row2 < 0 || row2 > sizeM)
	{
		printf("Error: incorrect index(es) of swappig rows.");
		return;
	}

	for (unsigned j = 0; j < sizeN; ++j)
	{
		swapInt(mass + row1 * sizeN + j, mass + row2 * sizeN + j);
		//swapInt(&(mass[row1 * sizeN + j]), &(mass[row2 * sizeN + j]));
	}
}

int** transposeStaticMatrix(int mass[][N], int sizeM)
{
	if (sizeM != N)
	{
		int **transposedMatrix = NULL;
		transposedMatrix = matrixMemoryAllocation(transposedMatrix, N, sizeM);

		for (int i = 0; i < sizeM; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				transposedMatrix[j][i] = mass[i][j];
			}
		}

		return transposedMatrix;
	}

	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			swapInt(&(mass[i][j]), &(mass[j][i]));
		}
	}

	return NULL;
}

int** transposeDynamicMatrix(int **mass, int sizeM, int sizeN)
{
	if (sizeM != sizeN)
	{
		int **transposedMatrix = NULL;
		transposedMatrix = matrixMemoryAllocation(transposedMatrix, sizeN, sizeM);

		for (int i = 0; i < sizeM; ++i)
		{
			for (int j = i + 1; j < sizeN; ++j)
			{
				transposedMatrix[j][i] = mass[i][j];
			}
		}

		return transposedMatrix;
	}

	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = i + 1; j < sizeN; ++j)
		{
			swapInt(&(mass[i][j]), &(mass[j][i]));
		}
	}

	return NULL;
}

int* transposeDynamicSingleMatrix(int *mass, int sizeM, int sizeN)
{
	if (sizeM != sizeN)
	{
		int *transposedMatrix = NULL;
		transposedMatrix = matrixMemoryAllocationSingle(transposedMatrix, sizeN, sizeM);

		for (int i = 0; i < sizeM; ++i)
		{
			for (int j = i + 1; j < sizeN; ++j)
			{
				transposedMatrix[j * sizeM + i] = mass[i * sizeN + j];
			}
		}

		return transposedMatrix;
	}

	for (int i = 0; i < sizeM; ++i)
	{
		for (int j = i + 1; j < sizeN; ++j)
		{
			swapInt(&(mass[i * sizeN + j]), &(mass[j * sizeM + i]));
		}
	}

	return NULL;
}

int** multiplyMatrixes(int **matrix1, int **matrix2, int m1, int n1, int m2, int n2)
{
	if (n1 != m2)
	{
		printf("Error: matrix [%dx%d] can't be multiplied with matrix [%dx%d].\n", m1, n1, m2, n2);
		return NULL;
	}

	int **multiMatr = NULL;
	multiMatr = matrixMemoryAllocation(multiMatr, m1, n2);

	for (int i = 0; i < m1; ++i)
	{
		for (int j = 0; j < n2; ++j)
		{
			multiMatr[i][j] = 0;
			for (int k = 0; k < n1; ++k)
			{
				multiMatr[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	return multiMatr;
}

int main()
{
	int **arr1 = NULL, **arr2 = NULL, **arr3 = NULL;
	
	arr1 = matrixMemoryAllocation(arr1, M, N);
	matrixRandomInitDynamic(arr1, M, N);
	
	arr2 = matrixMemoryAllocation(arr2, N, 2);
	matrixRandomInitDynamic(arr2, N, 2);
	
	printMatrixDynamic(arr1, M, N);
	printf("\n\n");
	printMatrixDynamic(arr2, N, 2);
	printf("\n\n");

	arr3 = multiplyMatrixes(arr1, arr2, M, N, N, 2);
	printMatrixDynamic(arr3, M, 2);

	getchar();
	return 0;
}