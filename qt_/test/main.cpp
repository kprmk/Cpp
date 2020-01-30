// 1. получить размер у пользователя
// 2. создание двумерного массива (динамическая)
// 3. сделать вывод на экран

#include <iostream>

using namespace std;

class spiral_matrix
{
private:
    int size_of_matrix;
    int **matrix;
public:
    // int user_input()
    // {
    // }

    spiral_matrix()
    {
        cout << "Hello, please enter the number: ";
        cin >> size_of_matrix;
        matrix = new int* [size_of_matrix];
        for (int i = 0; i < size_of_matrix; i++)
        {
            matrix[i] = new int [size_of_matrix];
            for (int j = 0; j < size_of_matrix; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    void print_matrix();

    // cur -> current
    // cur_str -> current string (index of string)
    // cur_col -> current column (index of column)
    // value -> there is current value
    void spiral()
    {
        int value = 1, cur_str = 0, cur_col = 0;
        for (int border = 0; 2 * border < size_of_matrix; border++)
        {
            cur_str = border;
            cur_col = border;
            for ( ;cur_col < size_of_matrix - border; cur_col++)
            {
                matrix[cur_str][cur_col] = value++;
            }
            for (cur_col--, cur_str++; cur_str < size_of_matrix - border; cur_str++)
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

    ~spiral_matrix()
    {
        for (int i = 0; i < size_of_matrix; i++)
        {
            delete [] matrix[i];
        }
        delete [] matrix;
        matrix = NULL;
    }
};

int main()
{
    spiral_matrix test1;
    test1.spiral();
    test1.print_matrix();
    return (0);
}

using namespace spiral_matrix;

void spiral_matrix::print_matrix()
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


// cur_str -> index of string
// cur_col -> index of culomn
int **spiral(int **matrix, int size)
{
    int value = 1, cur_str = 0, cur_col = 0;
    for (int border = 0; 2 * border < size * size; border++)
    { 
        cur_str = border;
        cur_col = border;
        for ( ; cur_col < size - border; cur_col++)
        {
            matrix[cur_str][cur_col] = value++;
        }
        for (cur_col--, cur_str++; cur_str < size - border; cur_str++)
        {
            matrix[cur_str][cur_col] = value++;
        }
        for (cur_col--, cur_str--; cur_col >= border; cur_col--)
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


