#include <iostream>
#include <cstdlib>
using namespace std;


/*
**  Выделение памяти для квадратной матрицы размером size на size
*/
int     **matrix_allocator(int **matr, const int size)
{
    int     counter = 0;

    matr = new int* [size];
    while (counter < size)
    {
        matr[counter] = new int [size];
        counter++;
    }
    return (matr);
}


/*
**  Присваивание рандомных (случайных) чисел матрице, используя функцию rand
**  #include <csdtdlib> для rand()
**  Используем оператор '%' для ограничения диапазона рандомных (случайных чисел)
*/
int     **matrix_initializer(int **matr, const int size)
{
    int     i = 0, j = 0;

    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            matr[i][j] = rand() % 5;
            j++;
        }
        i++;
    }
    return (matr);
}

/*
**  Вывод матрицы в стандартный вывод (печать на экран) размером size на size
*/
void    matrix_print(int **matr, const int size)
{
    int     i = 0, j = 0;

    cout << "Matrix " << size << " x " << size << ":" << endl;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            cout << matr[i][j] << " ";
            j++;
        }
        i++;
        cout << endl;
    }
    cout << endl;
}

/* 
**  Суммирование двух матриц (с динамическим выделением памяти для результата)
*/
int     **matrix_summer(int **matr_1, int **matr_2, const int size)
{
    int     **res;
    int     i = 0, j = 0;

    res = matrix_allocator(res, size);
    while(i < size)
    {
        j = 0;
        while(j < size)
        {
            res[i][j] = matr_1[i][j] + matr_2[i][j];
            j++;
        }
        i++;
    }
    return (res);
}

/*
**  Удаление динамически выделенной памяти для матрицы размером size на size
*/
void    matrix_delete(int **matr, const int size)
{
    int     counter = 0;

    while (counter < size)
    {
        delete [] matr[counter];
        counter++;
    }
    delete [] matr;
}

int main()
{
    //  Декларирование переменных для матриц и размера
    int             **matrix_1, **matrix_2, **matrix_sum;
    const int       size_of_matrix = 5;
    
    //  Выделение памяти для первой матрицы
    matrix_1 = matrix_allocator(matrix_1, size_of_matrix);
    //  Присваивание случайных чисел первой матрице
    matrix_1 = matrix_initializer(matrix_1, size_of_matrix);
    //  Вывод первой матрицы на экран
    cout << "First matrix:" << endl;
    matrix_print(matrix_1, size_of_matrix);  
    
    //  Выделение памяти для второй матрицы
    matrix_2 = matrix_allocator(matrix_2, size_of_matrix);
    //  Присваивание случайных чисел втор-ой матрице
    matrix_2 = matrix_initializer(matrix_2, size_of_matrix);
    //  Вывод второй матрицы на экран
    cout << "Second matrix:" << endl;
    matrix_print(matrix_2, size_of_matrix);

    //  Суммирование двух матриц
    matrix_sum = matrix_summer(matrix_1, matrix_2, size_of_matrix);
    //  Вывод рузультата на экран
    cout << "Result of sum:" << endl;
    matrix_print(matrix_sum, size_of_matrix);

    //  Освобождение ранее выделенной динамически памяти
    matrix_delete(matrix_1, size_of_matrix);
    matrix_delete(matrix_2, size_of_matrix);
    matrix_delete(matrix_sum, size_of_matrix);
    
    return 0;
}

