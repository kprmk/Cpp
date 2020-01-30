#include <iostream>

using namespace std;

int **init_matrix(int **matrix, int size_of_matrix)
{
    // 2
    matrix = new int* [size_of_matrix];
    for (int i = 0; i < size_of_matrix; i++)
    {
        matrix[i] = new int [size_of_matrix];
        for (int j = 0; j < size_of_matrix; j++)
        {
            matrix[i][j] = 0;
        }
    }
    return (matrix);
}

void print_matrix(int **matrix, int size_of_matrix)
{
    for (int i = 0; i < size_of_matrix; i++)
    {
        for (int j = 0; j < size_of_matrix; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}