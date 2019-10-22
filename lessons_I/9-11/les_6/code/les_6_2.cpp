#include <iostream>
using namespace std;

int main()
{
    cout << "Output:" << endl;
    int **array;
    int i, j;

    array = new int* [2];
    for (i = 0; i < 2; i++)
    {
        array[i] = new int[3];
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            array[i][j] = rand();
        }
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    return (0);
}

