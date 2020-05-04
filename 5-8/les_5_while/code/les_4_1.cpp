#include <iostream>
using namespace std;

int main()
{
    int num = 1;
    cout << "Start!" << endl;
    while (num < 6)
    {
        cout << num << endl;
        num = num + 1; // num++
    }
    cout << "Finish!" << endl;
    return (0);
}