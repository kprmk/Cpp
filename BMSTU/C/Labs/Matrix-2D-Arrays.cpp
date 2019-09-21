// ConsoleApplication5.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//������ ����������� ���������� ������� - ���������� ��������
//��� ��������� ������ ���� ��������� �� ������ �����,
//��������� �� �� ���� ������ ��� ���������� ������� ���������
//���������� ������������� ��������
const unsigned M = 8;

//������������� � ������ ������������ ���������� ������� � M ���������
void init_matrix_static(int A[][M], unsigned n);
void print_matrix_static(int A[][M], unsigned n);

//������������� � ������ ������������� ���������� �������
void init_matrix_dynamic(int* A[], unsigned n, unsigned m);
void print_matrix_dynamic(int* A[], unsigned n, unsigned m);

//������������� � ������ ����������� �������, ����������� �������� ������������ ��� n*m
void init_matrix_as_array(int A[], unsigned n, unsigned m);
void print_matrix_as_array(int A[], unsigned n, unsigned m);

void swap_int(int* a, int* b);					//���� �������� ���� ���������� ���� int
void swap_int_pointer(int** a, int** b);		//���� �������� ���� ���������� ���� int*
void swap(void* a, void* b, unsigned size);		//������������� ����

void transpose_matrix(int* A[], unsigned n);	//���������������� �������

												//����� ����� � �������� - ���������� ��� ������������ ��������� ��������
void swap_rows_in_matrix_static(int A[][M], unsigned row1, unsigned row2);
void swap_rows_in_matrix_dynamic(int* A[], unsigned row1, unsigned row2);
void swap_columns_in_matrix_static(int A[][M], unsigned n, unsigned column1, unsigned column2);
void swap_columns_in_matrix_dynamic(int* A[], unsigned n, unsigned column1, unsigned column2);

int main()
{
	//������ ����������� ������������ ���������� �������
	//����� �������� � ��� �� �������, ��� ��� ���������
	const unsigned N = 8;

	int A[N][M];	//���������� ������������� ��������� ������
	int** B;		//��������� ��� ������� � ������������� ���������� �������
	int* C;			//��������� ��� ������� � ������������� ����������� �������
	unsigned i;

	//������������� ���������� ���������� ��������� ����� 
	//� ����������� �� �������� �������
	srand(time(NULL));

	//��������� ������ �� ����������� ��������� ��������
	//�������� ��������, ��� ������ ������ �����������
	//��������� ��� �������� �������
	printf("Static matrix\n");
	init_matrix_static(A, N);
	print_matrix_static(A, N);
	printf("\n\n");

	//�������� � ��� �� ��������� ��������,
	//������������� ��� ��� ����������
	//�������� �������� �� ����� ���������� ���� � (int*)
	//�������� ������� �� ��,
	//��� ��� ����������� ���������� ��� ��������� �������
	printf("Static as array\n");
	init_matrix_as_array((int*)A, N, M);
	print_matrix_as_array((int*)A, N, M);
	printf("\n");
	//� ����� ����� �������� � � ��� � ��������� ��������
	print_matrix_static(A, N);
	printf("\n\n");

	//������������ ������ ��� ������������ ��������� ������
	B = (int**)malloc(N * sizeof(int*));
	for (i = 0; i < N; i++)
		B[i] = (int*)malloc(M * sizeof(int));

	//��������� ������ � ������������ ��������� ��������
	//�������� ������� �� ��,
	//��� ��� ����������� ���������� ��� ��������� �������
	printf("Dynamic matrix\n");
	init_matrix_dynamic(B, N, M);
	print_matrix_dynamic(B, N, M);
	printf("\n\n");

	//������������ ������ ��� ������������ ���������� ������
	//����������� N*M
	C = (int*)malloc(N * M * sizeof(int));

	//��������� ������ � ������������ ���������� �������� �
	//�������� ������� �� ��,
	//��� ��� ����������� ���������� ��� ��������� �������
	printf("Dynamic matrix as array\n");
	init_matrix_as_array(C, N, M);
	print_matrix_as_array(C, N, M);

	//������������ ������� � ������ � �����������
	//��� ��������� � ����������� � ������������
	//��������� ��������
	printf("Static:  %p\t%p\n", A, *A);
	printf("Dynamic: %p\t%p\n", B, *B);

	//�� �������� ������� ������!!!
	//������ ������� ������ ������ ���������
	for (i = 0; i < N; i++)
		free(B[i]);
	//������ ������ ��� ������� ����������
	free(B);

	//����������� ������ "��������" ������������� �������
	free(C);

	getchar();
	return 0;
}

void init_matrix_static(int A[][M], unsigned n)
{
	//�������� ��������!
	//��������� M ������������ � �������� ���� ���������

	unsigned i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < M; j++)				//M - ���������� ���������!
			A[i][j] = rand() % 100;
}

void print_matrix_static(int A[][M], unsigned n)
{
	//�������� ��������!
	//��������� M ������������ � �������� ���� ���������

	unsigned i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < M; j++)				//M - ���������� ���������!
			printf("%5d", A[i][j]);
		printf("\n");
	}
}

void init_matrix_dynamic(int* A[], unsigned n, unsigned m)
{
	//�������� ��������!
	//��� ����������� ���������� ��� ���������
	unsigned i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)			//m - �������� �������
			A[i][j] = rand() % 100;
}

void print_matrix_dynamic(int* A[], unsigned n, unsigned m)
{
	//�������� ��������!
	//��� ����������� ���������� ��� ���������
	unsigned i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)			//m - �������� �������
			printf("%5d", A[i][j]);
		printf("\n");
	}
}

void init_matrix_as_array(int A[], unsigned n, unsigned m)
{
	//�������� ��������!
	//��� ����������� ���������� ��� ���������

	unsigned i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)			//m - �������� �������
			A[i*m + j] = rand() % 100;	//������ A[i][j]
}

void print_matrix_as_array(int A[], unsigned n, unsigned m)
{
	//�������� ��������!
	//��� ����������� ���������� ��� ���������

	unsigned i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)			//m - �������� �������
			printf("%5d", A[i*m + j]);	//������ A[i][j]
		printf("\n");
	}
}

void swap_int(int* pa, int* pb)
{
	swap(pa, pb, sizeof(int));
	/*
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
	*/
}

void swap_int_pointer(int** pa, int** pb)
{
	swap(pa, pb, sizeof(int*));
	/*
	int* temp = *pa;
	*pa = *pb;
	*pb = temp;
	*/
}

void swap(void* pa, void* pb, unsigned size)
{
	//������������� swap
	//��� ����������� ������ �� ����������� ���� ������
	//������ ���������� �� ���������� ���
	//���������� ��������� �� void
	//�� ��� ���� � ����� ���� ������ ���������
	//����������� ������ � ������

	//������ ����������� ��������� ����������
	//���������� ����������� ���������� ����� �������� size ����
	void* temp = malloc(size);

	//������ ������������ ����������
	//�������� ������� ������
	memcpy(temp, pa, size);
	memcpy(pa, pb, size);
	memcpy(pb, temp, size);

	//�� �������� ������� ����������� ������������� ������!
	free(temp);
}

void transpose_matrix(int* A[], unsigned n)
{
	unsigned i, j;

	for (i = 0; i < n; i++)
		//���� ����� j=0 - ������ ���������� ������
		//� ������� ������������ ���� �����
		for (j = i + 1; j < n; j++)
			swap_int(&A[i][j], &A[j][i]);
	//swap_int(A[i]+j,A[j]+i);		//�������������� ������� ������ ������
}

void swap_rows_in_matrix_static(int A[][M], unsigned row1, unsigned row2)
{
	//��� ������ �� �������� ����� ���������,
	//��� �������� � ��� ����������� � ������ �������
	swap(A + row1, A + row2, M * sizeof(int));

	/*
	//���� �� ������������ ������������� swap,
	//����� �������� ��� ������ � �������������� ������������ ������
	int temp[M];

	memcpy(temp, A + row1, M * sizeof(int));
	memcpy(A + row1, A + row2, M * sizeof(int));
	memcpy(A + row2, temp, M * sizeof(int));
	*/

	/*
	//����� ����������� ������� - ������������ ���������
	for (unsigned j = 0; j < M; j++)
	swap_int(&A[row1][j], &A[row2][j]);
	*/
}

void swap_rows_in_matrix_dynamic(int* A[], unsigned row1, unsigned row2)
{
	//� ������������ ��������� ������� ��� ������ �� ��������
	//����� �������, ��� �� �� ������������ � ������ ��������
	//�������� ������� ����������
	//������� � ������ ������ ���������� ������ �������� �������
	//���� ����������
	swap_int_pointer(A + row1, A + row2);
}

void swap_columns_in_matrix_static(int A[][M], unsigned n, unsigned column1, unsigned column2)
{
	//��� ������ �� ��������� � ����� �������� ������������� ������
	//������� ������������ ������ ������� � �����������
	for (unsigned i = 0; i < n; i++)
		swap_int(&A[i][column1], &A[i][column2]);
}

void swap_columns_in_matrix_dynamic(int* A[], unsigned n, unsigned column1, unsigned column2)
{
	//��� ������ �� ��������� � ����� �������� ������������� ������
	//������� ������������ ������ ������� � �����������
	for (unsigned i = 0; i < n; i++)
		swap_int(&A[i][column1], &A[i][column2]);
}
