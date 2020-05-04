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
    int value = 1, cur_str = 0, cur_col = 0;
    for (int border = 0; 2 * border < size; border++)
    {
        cur_str = border;
        cur_col = border;
        for ( ;cur_col < size - border; cur_col++)
        {
            matrix[cur_str][cur_col] = value++;
        }
        for (cur_col--, cur_str++; cur_str < size - border; cur_str++)
        {
            matrix[cur_str][cur_col] = value++;
        }
        for (cur_str--, cur_col--; cur_col >= border; cur_col--)
        {
            matrix[cur_str][cur_col] = value++;
        }
        for (cur_col++, cur_str--; cur_str > border; cur_str--)
        {
            matrix[cur_str][cur_col] = value++;
        }
    }
}
