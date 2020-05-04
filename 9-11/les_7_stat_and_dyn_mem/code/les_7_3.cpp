#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int i = 0;

    cout << "Output:" << endl;
    while (i < 10)
    {
        cout << rand() << endl;
        i++;
    }
    return 0;
}

