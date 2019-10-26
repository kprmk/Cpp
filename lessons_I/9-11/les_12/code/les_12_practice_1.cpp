#include <iostream>
using namespace std;

int		recursion(int num)
{
	int		res = 1;

	while(num)
	{
		res *= num;
		num--;	
	}
	return (res);
}

int main()
{
	cout << "Output:" << endl;
	cout << recursion(3) << endl;
	return (0);
}
