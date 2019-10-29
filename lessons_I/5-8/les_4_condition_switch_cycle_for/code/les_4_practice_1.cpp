#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    cout << "Start!" << endl;
    while (num <= 10) // (num < 11)
    {
        cout << num << endl;
        num = num + 2;
    }
    cout << "Finish!" << endl;
    return (0);
}