#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *values;
	unsigned *rowIndexes;
	unsigned *colIndexes;
	unsigned rowNum;
	unsigned colNum;
	unsigned maxSize;
} SparseMatrix;

unsigned* rightShift(unsigned *mass, unsigned left, unsigned right)
{
	for (int i = right; i > left; --i)
	{
		mass[i] = mass[i - 1];
	}

	return mass;
}

unsigned* leftShift(unsigned *mass, unsigned left, unsigned right)
{
	for (int i = left; i < right; ++i)
	{
		mass[i] = mass[i + 1];
	}

	return mass;
}

int* rightShift(int *mass, unsigned left, unsigned right)
{
	for (int i = right; i > left; --i)
	{
		mass[i] = mass[i - 1];
	}

	return mass;
}

int* leftShift(int *mass, unsigned left, unsigned right)
{
	for (int i = left; i < right; ++i)
	{
		mass[i] = mass[i + 1];
	}

	return mass;
}

void sparseMatrixInit(SparseMatrix *matr, unsigned rows, unsigned cols, unsigned maxSize)
{
	matr->rowNum = rows;
	matr->colNum = cols;
	matr->maxSize = maxSize;

	matr->values = (int*)malloc(sizeof(int) * maxSize);
	matr->colIndexes = (unsigned*)malloc(sizeof(unsigned) * maxSize);
	matr->rowIndexes = (unsigned*)malloc(sizeof(unsigned) * (rows + 1));

	for (unsigned i = 0; i <= rows; ++i)
	{
		matr->rowIndexes[i] = 0;
	}
}

void sparseMatrixDelete(SparseMatrix *matr)
{
	free(matr->values);
	free(matr->colIndexes);
	free(matr->rowIndexes);
}

int getElement(SparseMatrix *matr, unsigned row, unsigned col)
{
	if (row >= matr->rowNum)
	{
		printf("Error: incorrect row number.\n");
		return 0;
	}

	if (col >= matr->colNum)
	{
		printf("Error: incorrect column number.\n");
		return 0;
	}

	for (unsigned j = matr->rowIndexes[row]; j < matr->rowIndexes[row + 1]; ++j)
	{
		if (col == matr->colIndexes[j])
		{
			return matr->values[j];
		}
	}

	return 0;
}

int setElement(SparseMatrix *matr, unsigned row, unsigned col, int value)
{
	/* ���� �������� :
		0 - �������� ���������� ��� ������� ��������
		1 - ������������ �������� ��������
		2 - ��� ������� �������� ��� �����
	*/

	unsigned i, j;

	if (row >= matr->rowNum)
	{
		printf("Error: incorrect row number.\n");
		return 1;
	}

	if (col >= matr->colNum)
	{
		printf("Error: incorrect column number.\n");
		return 1;
	}

	for (j = matr->rowIndexes[row]; j < matr->rowIndexes[row + 1]; ++j)
	{
		if (col == matr->colIndexes[j])
		{
			// ������� ������ ����� ���������

			if (!value)
			{
				if (matr->values[j])
				{
					leftShift(matr->colIndexes, j, matr->maxSize - 1);
					leftShift(matr->values, j, matr->maxSize - 1);
					for (unsigned k = row + 1; k <= matr->rowNum; ++k)
					{
						matr->rowIndexes[k]--;
					}
				}

				return 0;
			}
			
			matr->values[j] = value;
			return 0;
		}
	}

	// ������� �������

	if (matr->rowIndexes[matr->rowNum] == matr->maxSize)
	{
		// ��� ������� ��� �����
		return 2;
	}

	if (value)
	{
		for (i = row + 1; i <= matr->rowNum; ++i)
		{
			matr->rowIndexes[i]++;
		}

		for (j = matr->rowIndexes[row]; j < matr->rowIndexes[row + 1] - 1; ++j)
		{
			if (col < matr->colIndexes[j])
			{
				rightShift(matr->colIndexes, j, matr->maxSize - 1);
				rightShift(matr->values, j, matr->maxSize - 1);

				matr->colIndexes[j] = col;
				matr->values[j] = value;

				return 0;
			}
		}

		// ���� col ������ ���� �������� � ��������� ��������
		rightShift(matr->colIndexes, j, matr->maxSize - 1);
		rightShift(matr->values, j, matr->maxSize - 1);

		matr->colIndexes[j] = col;
		matr->values[j] = value;
	}

	return 0;
}

void printMatrix(SparseMatrix *matr)
{
	for (unsigned i = 0; i < matr->rowNum; ++i)
	{
		for (unsigned j = 0; j < matr->colNum; ++j)
		{
			printf("%4d", getElement(matr, i, j));
		}
		printf("\n");
	}
}

void printSparseMatrix(SparseMatrix *matr)
{
	for (unsigned i = 0; i < matr->rowNum; ++i)
	{
		for (unsigned j = matr->rowIndexes[i]; j < matr->rowIndexes[i + 1]; ++j)
		{
			printf("[I: %2u, J: %2u] -> %4d\n", i, matr->colIndexes[j], matr->values[j]);
		}
	}
}

void fillMatrixFromFile(SparseMatrix* pMatrix, char* fileName)
{
	/*
	������� ������������� ������� �� ������ ������
	� ��������� �����
	�������������� ������ ������ � ���� ����� �����
	(row, column, value)
	*/

	FILE* fp;

	//��������� ���� �� ������ ("r" - read)
	if (!(fp = fopen(fileName, "r")))
	{
		//��������� ��������, ����� ��� ������� �� �������
		printf("Can not open file!\n");
		return;
	}

	unsigned row, column;
	int value;

	do
	{
		//���������, ������� �� fscanf ��������� 3 ��������, ��� � ��������
		if (fscanf(fp, "%u %u %d", &row, &column, &value) == 3)
			//���� �� - ����� �������� set_element
			setElement(pMatrix, row, column, value);
		else
			//���� ��� - � ����� ���������� ������,
			//���������� ��� ���������
			break;
	} while (!feof(fp));
	//������� ���������� ����� - ����� ��������� ����� �����

	//�� �������� ��������� ������ � ������
	fclose(fp);
}

void prepareFile(char* fileName)
{
	/*
	������� ��������� ��������� ����,
	� ������� ������������ ������ �����:
	(row, column, value)
	*/

	FILE* fp;
	char buf[50];

	//��������� ���� �� ������ ("w" - write)
	if (!(fp = fopen(fileName, "w")))
	{
		//��������� ��������, ����� ��� ������� �� �������
		printf("Can not open file!\n");
		return;
	}

	do
	{
		//������ ������ �� ������ ������������ �����
		fgets(buf, 50, stdin);
		//� ��� �� ����� � � �������� ����
		fputs(buf, fp);
	} while (buf[0] != '\n');
	//�������, ���� �������� ������ - ������
	//(����� ��� ������ �������� ������)

	//�� �������� ��������� ������ � ������
	fclose(fp);
}

int main()
{
	SparseMatrix matrix;

	//prepareFile("matrix.txt");		
	sparseMatrixInit(&matrix, 5, 5, 10);
	fillMatrixFromFile(&matrix, "matrix.txt");
	
	printSparseMatrix(&matrix);
	printf("\n\n");
	printMatrix(&matrix);

	setElement(&matrix, 1, 1, -13);
	setElement(&matrix, 0, 0, 0);
	setElement(&matrix, 3, 2, 10);
	setElement(&matrix, 2, 4, 10);
	printf("\n\n");
	printMatrix(&matrix);

	setElement(&matrix, 2, 3, 0);
	setElement(&matrix, 2, 4, 10);
	printf("\n\n");
	printMatrix(&matrix);
	
	sparseMatrixDelete(&matrix);

	getchar();
	return 0;
}