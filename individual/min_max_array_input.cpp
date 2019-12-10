#include <iostream>
using namespace std;

int main()
{
    int len;
    cout << "HELLO" << endl;
    cout << "Please, enter the length of array" << endl;
    cin >> len;
    int array[len];
    for (int j = 0; j < len; j++)
    {
        cout << "Please, enter the number"<< endl;
        cin >> array[j];
    }
    int min = array[0];
    int max = array[0];
    for (int i = 0; i < len; i++)
    {
        if (min > array[i])
        {
            min = array[i];
        }
        if (max < array[i])
        {
            max = array[i];
        }
    }
    cout << "min is " << min << endl;
    cout << "max is " << max << endl;
    cout << "min + max = " << min + max << endl;
    return (0);
}

