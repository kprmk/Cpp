#include <iostream>

using namespace std;

int user_input()
{
    int n = 0;
    cout << "Please, enter the size of\n the square matrix (one number): ";
    std::cin >> n;
    cout << endl;
    return (n);
}

int **init_matrix(int **matrix, int size_of_matrix)
{
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

int **spiral(int **matrix, int size)
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
    return (matrix);
}

void print_matrix(int **matrix, int size_of_matrix)
{
    for (int i = 0; i < size_of_matrix; i++)
    {
        for (int j = 0; j < size_of_matrix; j++)
        {
            cout.width(3);
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void del_memory(int ***matrix, int size_of_matrix)
{
    for(int q = 0; q < size_of_matrix; q++)
        delete [] (*matrix)[q];
    delete [] (*matrix);
    *matrix = NULL;
}

int main()
{
    int **matrix = NULL;
    int size = 0;

    size = user_input();
    matrix = init_matrix(matrix, size);
    matrix = spiral(matrix, size);
    print_matrix(matrix, size);
    del_memory(&matrix, size);
    return 0;
}


