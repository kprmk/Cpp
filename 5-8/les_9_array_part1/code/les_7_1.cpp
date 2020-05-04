#include <iostream>
using namespace std;

int main()
{
    int age = 16;
    cout << "Output:" << endl;
    switch (age) 
    {
        case 16:
            cout << "Too young" << endl;
        case 42:
            cout << "Adult" << endl;
        case 70:
            cout << "Senior" << endl;
        default:
            cout << "This is default case" << endl;
    }
    return (0);
}

