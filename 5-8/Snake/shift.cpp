#include <iostream>
#include <cstdlib>

#include <vector>

using namespace std;

void print_snake_1(vector<int> x, int width)
{
	for (int i = 0; i < width; i++)
		cout << '#';
	cout << endl;
	for(int i = 0; i < width; i++)
	{
		if (i == 0 || i == width - 1)
			cout << '#';
		else
		{
			bool is_empty = false;
			for (int j = x.size() - 1; j > (x.size() - 1) - 2; j--)
			{
				if (x[j] == i)
				{
					cout << "o";
					is_empty = true;
				}
			}
			if (is_empty == false)
				cout << ' ';
		}
	}
	cout << endl;
	for (int i = 0; i < width; i++)
		cout << '#';
	cout << endl;
}

int main()
{
	vector<int> x(1, 3);
	x.push_back(4);
	x.push_back(5);
	x.push_back(6);
	x.push_back(7);


	print_snake_1(x, 10);
    return 0;
}