#include "spiral_matrix.h"

spiral_matrix::spiral_matrix(int n )
{
    this->n = n;
    pointer =  new  int * [n];
    for(int q = 0; q < n; q++)
    {
        *(pointer + q) = new int [n];
        for(int p = 0; p < n; p++)
        {
            *(*(pointer + q) + p)= 0;
        }
    }
}

spiral_matrix::~spiral_matrix()
{
    for(int q = 0; q < n; q++)
        delete [] *(pointer + q);
    delete [] pointer;
}

void spiral_matrix::matrix_print()
{
    cout << endl;
    for(int q = 0; q < n; q++)
    {
        for(int p = 0; p < n; p++)
        {
            cout.width(3);
            cout << pointer[q][p] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void spiral_matrix::matrix_circle_around()
{
    //srand(time(NULL));
    int j , q, p;
    p = (n % 2)? n / 2 + 1: n / 2;
    for(int i = 0, g = 1; i < p; i++)
    {
        for (j = i; j < n - i; j++)
        {
            pointer[i][j] = g++ /*rand() % n*n*/;
        }
        g--;
        for (q = i; q < n - i; q++)
        {
            pointer[q][n - i - 1] =  g++ /*rand() % n*n*/;
        }
        g--;
        for (j-- ; j >= i ; j--)
        {
           pointer[n - i - 1][j] =  g++ /*rand() % n*n*/;
        }
        g--;
        for(q-- ;  q > i ;q-- )
        {
            pointer[q][i] =  g++ /*rand() % n*n*/;
        }
    }
}
