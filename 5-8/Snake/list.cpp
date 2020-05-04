#include <iostream>
#include <list>

using namespace std;

void print_list(list<int> input)
{
	for (list<int>::iterator it = input.begin(); it != input.end(); it++)
	{
		cout << *it << endl;
	}
}

int main()
{
	list<int> coords;

	coords.push_back(100);
	coords.push_back(1);
	coords.push_back(2);
	coords.push_back(3);

	print_list(coords);

	return (0);
}