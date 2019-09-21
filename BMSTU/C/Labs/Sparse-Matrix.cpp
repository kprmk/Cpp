#include <stdio.h>
#include <stdlib.h>


typedef		//��������� ������� ����������� ���� �� ���������
struct	//sparseMatrix		//���������� ��������� � ������ ������ �������� ��������������
{
	unsigned rows, columns;		//����� ����� � ��������
	unsigned maxSize;			//������������� ����� ��������� ���������, ���������� ������ �������
	unsigned* rowIndexes;		//��������� ��� ������ � ������������ �������� ��������
	unsigned* columnIndexes;	//��������� ��� ������ � ������������ �������� ������� ��������
	int* values;				//��������� ��� ������ � ������������ �������� �������� ���������
}
sparseMatrix;		//��� ����, ������� ����������� typedef

					//������������� ������ � ����������� �������� � ������������ ����������� ������������� ������
void matrix_allocation(sparseMatrix* pMatrix, unsigned rows, unsigned columns, unsigned maxSize);
void matrix_free(sparseMatrix* pMatrix);

//��������� � ������ �������� � �������� �������
int set_element(sparseMatrix* pMatrix, unsigned row, unsigned column, int value);
int get_element(sparseMatrix* pMatrix, unsigned row, unsigned column);

//��������������� ����� ���� �������
void print_matrix(sparseMatrix* pMatrix);		//������������� ���
void print_sparseMatrix(sparseMatrix* pMatrix);	//����������� �������������

												//���������������� ���� �������� ���� int � ����������
int input_int(char* caption);

//������������� ����������� �������
void init_from_console(sparseMatrix* pMatrix);				//� ����������
void init_from_file(sparseMatrix* pMatrix, char* fileName);	//�� �����

															//���������� ����� ��� ������������� �������
void prepare_file(char* fileName);

int main()
{
	sparseMatrix matrix;

	//������� ������ � ��������,
	//� ��� ����� �������� ������������ ������
	matrix_allocation(&matrix, 4, 5, 10);

	//������������� � ����������
	//init_from_console(&matrix);

	//������������� �� �����
	//prepare_file("data.txt");
	init_from_file(&matrix, "data.txt");
	print_matrix(&matrix);
	print_sparseMatrix(&matrix);

	//����������� ����������� ������������� ������
	matrix_free(&matrix);

	getchar();
	return 0;
}

void matrix_allocation(sparseMatrix* pMatrix, unsigned rows, unsigned columns, unsigned maxSize)
{
	/*
	���������� ������ � ����������� ��������
	*/

	//�������������� ���� ���������
	//���������� ���������� �������
	pMatrix->rows = rows;
	pMatrix->columns = columns;
	pMatrix->maxSize = maxSize;

	//����������� ������������ ������ ��� �������
	pMatrix->rowIndexes = (unsigned*)malloc((rows + 1) * sizeof(unsigned));
	pMatrix->columnIndexes = (unsigned*)malloc(maxSize * sizeof(unsigned));
	pMatrix->values = (int*)malloc(maxSize * sizeof(int));

	//�������� �������� ������� rowIndexes
	for (unsigned i = 0; i < (rows + 1); i++)
		pMatrix->rowIndexes[i] = 0;
}

void matrix_free(sparseMatrix* pMatrix)
{
	//����������� ����������� ������������� ������
	free(pMatrix->rowIndexes);
	free(pMatrix->columnIndexes);
	free(pMatrix->values);
}

int set_element(sparseMatrix* pMatrix, unsigned row, unsigned column, int value)
{
	/*
	������� ��������� ��������,
	�������� � ������ row
	� ������� column
	� �������� value

	���� ��������:
	0 - �������� ���������� ��� ������� ��������
	1 - ������������ �������� ��������
	2 - ��� ������� �������� ��� �����
	*/

	unsigned i, j;

	//�������� ������������ �������� �������� ������ � �������
	//������� � ����� �������� 1
	if ((row > pMatrix->rows) || (column > pMatrix->columns))
		return 1;

	//��������� ����� ������� ������:
	//������� ��� ���� ����������� �������
	for (i = pMatrix->rowIndexes[row]; i < pMatrix->rowIndexes[row + 1]; i++)
		if (pMatrix->columnIndexes[i] == column)
		{
			if (value)
			{
				//���� ����� ����� �������,
				//� value �� ����� 0
				//��������� �������� � �������
				//� ������� � ����� �������� 0
				pMatrix->values[i] = value;
				return 0;
			}

			//�������� � ��� ����� ����,
			//����� value ����� 0,
			//�.�. ����� ������� �������� �������

			//��� ����� �������� �������
			//values � columnIndexes ����� �� 1 �������
			for (j = i; j < (pMatrix->rowIndexes[pMatrix->rows] - 1); j++)
			{
				pMatrix->values[j] = pMatrix->values[j + 1];
				pMatrix->columnIndexes[j] = pMatrix->columnIndexes[j + 1];
			}

			//� ��������� �� 1 �������� ���������
			//� ������� rowIndexes ������� �� ��������� ������
			for (j = row + 1; j < (pMatrix->rows + 1); j++)
				pMatrix->rowIndexes[j]--;

			//������� � ����� �������� 0
			return 0;
		}

	//� ��� ����� ��������, ���� � ����������� �������
	//�� ����������� ������� � ��������� ���������

	//�������� ������������ ������
	//0 �������� �������� ������ 0
	//������� � ����� �������� 0
	if (!value)
		return 0;

	//���������, ������ �� ��� ������� ������ ���
	//���������� ��� ������ ���������� ��������
	//������� � ����� �������� 2
	if (pMatrix->rowIndexes[pMatrix->rows] == pMatrix->maxSize)
		return 2;

	//���� ������ ������ ���������,
	//����������� ����� ��� ������ ��������,
	//�������� ����� ������ ������������ ���������
	//�������� values � columnIndexes
	for (j = pMatrix->rowIndexes[pMatrix->rows]; j > i; j--)
	{
		pMatrix->values[j] = pMatrix->values[j - 1];
		pMatrix->columnIndexes[j] = pMatrix->columnIndexes[j - 1];
	}

	//�� �������������� ����� ���������� ����� �������
	pMatrix->values[i] = value;
	pMatrix->columnIndexes[i] = column;

	//� ��������� �� 1 �������� ���������
	//� ������� rowIndexes ������� �� ��������� ������
	for (j = row + 1; j < (pMatrix->rows + 1); j++)
		pMatrix->rowIndexes[j]++;

	//������� � ����� �������� 0
	return 0;
}

int get_element(sparseMatrix* pMatrix, unsigned row, unsigned column)
{
	/*
	������� ���������� �������� ��������,
	������� ����� � ������� �� �����������
	������ row � ������� column
	*/

	//���������� � ������� columnIndexes
	//������ ��������� ���������, ������� �����
	//�� pMatrix->rowIndexes[row]
	//�� pMatrix->rowIndexes[row + 1]
	for (unsigned i = pMatrix->rowIndexes[row]; i < pMatrix->rowIndexes[row + 1]; i++)
		if (pMatrix->columnIndexes[i] == column)
			return pMatrix->values[i];

	return 0;
}

void print_matrix(sparseMatrix* pMatrix)
{
	/*
	������� ������������� ������� � ������� ������������� ����
	*/

	unsigned i, j;

	//������ �������� �� ���� ��������� ��������� ��������
	//�� ������� � �� ��������
	for (i = 0; i < pMatrix->rows; i++)
	{
		for (j = 0; j < pMatrix->columns; j++)
			printf("%4d", get_element(pMatrix, i, j));
		printf("\n");
	}
	printf("\n\n");
}

void print_sparseMatrix(sparseMatrix* pMatrix)
{
	unsigned i;

	//���� ������ ������ ����� (rows + 1) �������
	printf("Row indexes array:\n");
	for (i = 0; i < (pMatrix->rows + 1); i++)
		printf("%4u", pMatrix->rowIndexes[i]);

	//� ���� ������� ����� ���������� ��������� ������������
	//��������� ���������� �������� ������� rowIndexes
	printf("\nColumn indexes array:\n");
	for (i = 0; i < pMatrix->rowIndexes[pMatrix->rows]; i++)
		printf("%4u", pMatrix->columnIndexes[i]);

	printf("\nValues array:\n");
	for (i = 0; i < pMatrix->rowIndexes[pMatrix->rows]; i++)
		printf("%4d", pMatrix->values[i]);

	printf("\n\n");
}

int input_int(char* caption)
{
	/*
	������� ��������� ���������������� ���� ������ �����
	�������� caption - ��� ������, ������� ��������
	���������� ��� ������������, ��� ��� ���������� �������
	*/

	int input;

	//���������� ����������� ����
	do
	{
		//������� ����������� ������ ����� ��������
		printf("Input %s\n", caption);
		//���� ������� ��������� 1 ����� �����
		if (scanf("%d", &input) == 1)
			//������� �� �����
			break;
		//� ��������� ������
		printf("Invalid input!\n");
		//������� �������, ���������� � ������ �����
		while (getchar() != '\n');
	} while (1);

	//������� �������, ���������� � ������ �����
	while (getchar() != '\n');

	//���������� ����������� � ���������� ��������
	return input;
}

void init_from_console(sparseMatrix* pMatrix)
{
	/*
	������� ��������� ���������������� ����
	��������� �������
	*/

	int row, column;
	int value;
	char c;

	//���������� ����������� ����
	do
	{
		//����������� � ������������ ���������,
		//����������� ��� ������ set_element
		row = input_int("row");
		column = input_int("column");
		value = input_int("value");

		//�������� set_element, ��� ���� ������������
		//��� ��� �������� ��� ������ switch
		switch (set_element(pMatrix, row, column, value))
		{
		case 1: printf("Index out of range!\n");  break;
		case 2: printf("Buffer overflow!\n"); break;
		default: print_matrix(pMatrix); break;
		}

		//���������� ��� ���� ����������� ����
		do
		{
			printf("Continue? (y/n)\n");
			//������ ���� ������
			c = getchar();
			//� ������ �������������� ������ ������������
			//������� �� ���������� �����, ��� �� �����
			//�������� �������� �����
			if (c == 'y' || c == 'Y')
				break;
			//� ������ �������������� ������ ������������
			//��������� ���������� ������� � �����
			if (c == 'n' || c == 'N')
				return;
			//�� ���� ��������� �������
			printf("Invalid input!\n");
			//������� �������, ���������� � ������ �����
			while (getchar() != '\n');
		} while (1);

	} while (1);
}

void init_from_file(sparseMatrix* pMatrix, char* fileName)
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
			set_element(pMatrix, row, column, value);
		else
			//���� ��� - � ����� ���������� ������,
			//���������� ��� ���������
			break;
	} while (!feof(fp));
	//������� ���������� ����� - ����� ��������� ����� �����

	//�� �������� ��������� ������ � ������
	fclose(fp);
}

void prepare_file(char* fileName)
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
