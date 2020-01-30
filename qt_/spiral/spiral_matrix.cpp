#include "spiral_matrix.h"

spiral_matrix::spiral_matrix()
{
    cout << "Please, enter the size of\n the square matrix (one number): ";
    std::cin >> this->size;
    cout << endl;
    matrix =  new  int * [size];
    for(int q = 0; q < size; q++)
    {
        *(matrix + q) = new int [size];
        for(int p = 0; p < size; p++)
        {
            *(*(matrix + q) + p)= 0;
        }
    }
}

spiral_matrix::~spiral_matrix()
{
    for(int q = 0; q < size; q++)
        delete [] *(matrix + q);
    delete [] matrix;
}

void spiral_matrix::matrix_print()
{
    cout << endl;
    for(int q = 0; q < size; q++)
    {
        for(int p = 0; p < size; p++)
        {
            cout.width(3);
            cout << matrix[q][p] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void spiral_matrix::matrix_circle_around()
{
    int cur_col, cur_str, amount_of_iter;

    amount_of_iter = (size % 2) ? size / 2 + 1: size / 2;
    for(int border = 0, value = 0; border < amount_of_iter; border++)
    {
        for (cur_col = border; cur_col < size - border; cur_col++)
        {
            matrix[border][cur_col] = ++value;
        }
        for (cur_str = border + 1; cur_str < size - border; cur_str++)
        {
            matrix[cur_str][size - border - 1] = ++value;
        }
        for (cur_col -= 2; cur_col >= border; cur_col--)
        {
           matrix[size - border - 1][cur_col] = ++value;
        }
        for(cur_str -= 2; cur_str > border; cur_str--)
        {
            matrix[cur_str][border] = ++value;
        }
    }
}
