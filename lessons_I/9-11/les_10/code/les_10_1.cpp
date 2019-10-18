#include <iostream>
using namespace std;

template <class T>
T sum(T a, T b) 
{
    return (a + b);
}

int main () 
{
    cout << "Output:" << endl;
    double x = 7.15, y = 15.54;
    int a = 10, b = 20;
    cout << sum(x, y) << endl;
    cout << sum(a, b) << endl;
    return (0);
}

