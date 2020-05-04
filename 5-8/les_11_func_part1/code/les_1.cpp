#include <iostream>
using namespace std;

void divide(int a, int b)
{
	if (b != 0)
		cout << a / b << endl;
}

int main()
{
    int first_num = 16;
    int second_num = 2;

	divide(first_num, second_num);
	
    return (0);
}

