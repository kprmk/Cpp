// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//вторая размерность двумерного массива - количество столбцов
//эта константа должна быть объявлена на уровне файла,
//поскольку на неё есть ссылки при объявлении функций обработки
//статически распределённых массивов
const unsigned M = 8;

//инициализация и печать статического двумерного массива с M столбцами
void init_matrix_static(int A[][M], unsigned n);
void print_matrix_static(int A[][M], unsigned n);

//инициализация и печать динамического двумерного массива
void init_matrix_dynamic(int* A[], unsigned n, unsigned m);
void print_matrix_dynamic(int* A[], unsigned n, unsigned m);

//инициализация и печать одномерного массива, размерность которого определяется как n*m
void init_matrix_as_array(int A[], unsigned n, unsigned m);
void print_matrix_as_array(int A[], unsigned n, unsigned m);

void swap_int(int* a, int* b);					//своп значений двух переменных типа int
void swap_int_pointer(int** a, int** b);		//своп значений двух переменных типа int*
void swap(void* a, void* b, unsigned size);		//универсальный своп

void transpose_matrix(int* A[], unsigned n);	//транспонирование матрицы

												//обмен строк и столбцов - реализация для статического двумерных массивов
void swap_rows_in_matrix_static(int A[][M], unsigned row1, unsigned row2);
void swap_rows_in_matrix_dynamic(int* A[], unsigned row1, unsigned row2);
void swap_columns_in_matrix_static(int A[][M], unsigned n, unsigned column1, unsigned column2);
void swap_columns_in_matrix_dynamic(int* A[], unsigned n, unsigned column1, unsigned column2);

int main()
{
	//первую размерность статического двумерного массива
	//можем задавать в той же функции, где его объявляем
	const unsigned N = 8;

	int A[N][M];	//статически распределённый двумерный массив
	int** B;		//указатель для доступа к динамическому двумерному массиву
	int* C;			//указатель для доступа к динамическому одномерному массиву
	unsigned i;

	//инициализация параметров генератора случайных чисел 
	//в зависимости от текущего времени
	srand(time(NULL));

	//тестируем работу со статическим двумерным массивом
	//обратите внимание, что только первая размерность
	//передаётся как параметр функции
	printf("Static matrix\n");
	init_matrix_static(A, N);
	print_matrix_static(A, N);
	printf("\n\n");

	//работаем с тем же двумерным массивом,
	//рассматриваем его как одномерный
	//обратите внимание на явное приведение типа к (int*)
	//обратите внимане на то,
	//что обе размерности передаются как параметры функции
	printf("Static as array\n");
	init_matrix_as_array((int*)A, N, M);
	print_matrix_as_array((int*)A, N, M);
	printf("\n");
	//а затем вновь работаем с А как с двумерным массивом
	print_matrix_static(A, N);
	printf("\n\n");

	//распределяем память под динамический двумерный массив
	B = (int**)malloc(N * sizeof(int*));
	for (i = 0; i < N; i++)
		B[i] = (int*)malloc(M * sizeof(int));

	//тестируем работу с динамическим двумерным массивом
	//обратите внимане на то,
	//что обе размерности передаются как параметры функции
	printf("Dynamic matrix\n");
	init_matrix_dynamic(B, N, M);
	print_matrix_dynamic(B, N, M);
	printf("\n\n");

	//распределяем память под динамический одномерный массив
	//размерности N*M
	C = (int*)malloc(N * M * sizeof(int));

	//тестируем работу с динамическим одномерным массивом С
	//обратите внимане на то,
	//что обе размерности передаются как параметры функции
	printf("Dynamic matrix as array\n");
	init_matrix_as_array(C, N, M);
	print_matrix_as_array(C, N, M);

	//демонстрация разницы в работе с указателями
	//при адресации к статическим и динамическим
	//двумерным массивам
	printf("Static:  %p\t%p\n", A, *A);
	printf("Dynamic: %p\t%p\n", B, *B);

	//не забываем чистить память!!!
	//чистим сначала каждую строку элементов
	for (i = 0; i < N; i++)
		free(B[i]);
	//чистим память для массива указателей
	free(B);

	//освобождаем память "длинного" динамического массива
	free(C);

	getchar();
	return 0;
}

void init_matrix_static(int A[][M], unsigned n)
{
	//обратите внимание!
	//константа M используется в описании типа параметра

	unsigned i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < M; j++)				//M - глобальная константа!
			A[i][j] = rand() % 100;
}

void print_matrix_static(int A[][M], unsigned n)
{
	//обратите внимание!
	//константа M используется в описании типа параметра

	unsigned i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < M; j++)				//M - глобальная константа!
			printf("%5d", A[i][j]);
		printf("\n");
	}
}

void init_matrix_dynamic(int* A[], unsigned n, unsigned m)
{
	//обратите внимание!
	//обе размерности передаются как параметры
	unsigned i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)			//m - параметр функции
			A[i][j] = rand() % 100;
}

void print_matrix_dynamic(int* A[], unsigned n, unsigned m)
{
	//обратите внимание!
	//обе размерности передаются как параметры
	unsigned i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)			//m - параметр функции
			printf("%5d", A[i][j]);
		printf("\n");
	}
}

void init_matrix_as_array(int A[], unsigned n, unsigned m)
{
	//обратите внимание!
	//обе размерности передаются как параметры

	unsigned i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)			//m - параметр функции
			A[i*m + j] = rand() % 100;	//вместо A[i][j]
}

void print_matrix_as_array(int A[], unsigned n, unsigned m)
{
	//обратите внимание!
	//обе размерности передаются как параметры

	unsigned i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)			//m - параметр функции
			printf("%5d", A[i*m + j]);	//вместо A[i][j]
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
	//универсальный swap
	//это достигается уходом от конкретного типа данных
	//вместо указателей на конкретный тип
	//используем указатель на void
	//но при этом в явном виде должны указывать
	//размерность данных в байтах

	//вместо статической временной переменной
	//используем динамически выделенный буфер размером size байт
	void* temp = malloc(size);

	//вместо присваиваний переменных
	//копируем области памяти
	memcpy(temp, pa, size);
	memcpy(pa, pb, size);
	memcpy(pb, temp, size);

	//не забываем чистить динамически распределённую память!
	free(temp);
}

void transpose_matrix(int* A[], unsigned n)
{
	unsigned i, j;

	for (i = 0; i < n; i++)
		//если будет j=0 - обмены произойдут дважды
		//и взаимно компенсируют друг друга
		for (j = i + 1; j < n; j++)
			swap_int(&A[i][j], &A[j][i]);
	//swap_int(A[i]+j,A[j]+i);		//альтернативный вариант записи адреса
}

void swap_rows_in_matrix_static(int A[][M], unsigned row1, unsigned row2)
{
	//при работе со строками нужно учитывать,
	//что элементы в них расположены в памяти вподряд
	swap(A + row1, A + row2, M * sizeof(int));

	/*
	//если не использовать универсальный swap,
	//можно написать его аналог с использованием статического буфера
	int temp[M];

	memcpy(temp, A + row1, M * sizeof(int));
	memcpy(A + row1, A + row2, M * sizeof(int));
	memcpy(A + row2, temp, M * sizeof(int));
	*/

	/*
	//самый примитивный вариант - поэлементная обработка
	for (unsigned j = 0; j < M; j++)
	swap_int(&A[row1][j], &A[row2][j]);
	*/
}

void swap_rows_in_matrix_dynamic(int* A[], unsigned row1, unsigned row2)
{
	//в динамическом двумерном массиве при работе со строками
	//важно помнить, что за их расположение в памяти отвечают
	//элементы массива указателей
	//поэтому в данном случае достаточно просто поменять местами
	//пару указателей
	swap_int_pointer(A + row1, A + row2);
}

void swap_columns_in_matrix_static(int A[][M], unsigned n, unsigned column1, unsigned column2)
{
	//при работе со столбцами в любом варианте распределения памяти
	//придётся обрабатывать каждый элемент в отдельности
	for (unsigned i = 0; i < n; i++)
		swap_int(&A[i][column1], &A[i][column2]);
}

void swap_columns_in_matrix_dynamic(int* A[], unsigned n, unsigned column1, unsigned column2)
{
	//при работе со столбцами в любом варианте распределения памяти
	//придётся обрабатывать каждый элемент в отдельности
	for (unsigned i = 0; i < n; i++)
		swap_int(&A[i][column1], &A[i][column2]);
}
