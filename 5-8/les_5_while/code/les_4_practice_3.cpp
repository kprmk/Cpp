#include <iostream>
using namespace std;

int main()
{
    int num = 11;
    cout << "Start!" << endl;
    while (num >= 1)
    {
        cout << num << endl;
        num = num - 2;
    }
    cout << "Finish!" << endl;
    return (0);
}