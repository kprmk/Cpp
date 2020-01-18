#include <iostream>
using namespace std;

void division(int num_1, int num_2)
{
    if (num_2 == 0)
    {
        cout << "error!" << endl;
    }
    else
    {
        cout << num_1 / num_2 << endl;   
    }
}

void print_hello()
{
    cout << "HELLO" << endl;
}

int main()
{
    int n_1, n_2;
    cin >> n_1;
    cin >> n_2;
    division(n_1, n_2);
    return (0);
}