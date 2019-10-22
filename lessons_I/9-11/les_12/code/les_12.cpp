#include <iostream>
using namespace std;

int	recursion(int num)
{
	return (num ? num * recursion(num - 1): 1);
	/*
	if (!num) // num == 0
	{
		return (1);
	}
	else
	{
		return (num * recursion(num - 1))
	}
	*/
}

int main()
{
	cout << "Output:" << endl;
	cout << recursion(3) << endl;
	return (0);
}
