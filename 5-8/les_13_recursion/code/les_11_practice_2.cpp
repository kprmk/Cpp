#include <iostream>
using namespace std;

int 	fib_rec(int num)
{
	if (num == 1 || num == 2)
	{
		return (1);
	}
	else
	{
		return (fib_rec(num - 1) + fib_rec(num - 2));
	}
}

int main()
{
	cout << "Output:" << endl;
	cout << fib_rec(7) << endl;
	return (0);
}
