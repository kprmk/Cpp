#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> v)
{
	for (auto i : v)
		cout << i << ' ';
	cout << endl;
}

bool check_beat(vector<int> x, vector<int> y)
{
	if (x.size() != y.size())
		return (true);
	for (int i = 0; i < x.size(); i++)
	{
		for (int j = i + 1; j < x.size(); j++)
		{
			if (x[i] == x[j] || y[i] == y[j] || 
				abs(x[i] - x[j]) == abs(y[i] - y[j]))
					return (true);
		}
	}
	return (false);
}

int main()
{
	int size = 4;

	// int x_mas[] = {1, 2, 3, 4};
	// int y_mas[] = {2, 4, 1, 1};

	vector<int> x;
	vector<int> y;

	string input;
 	for (int i = 0; i < 4; i++)
	{
		getline(cin, input);
		x.push_back(input[0] - '0');
		y.push_back(input[2] - '0');
	}

	print_vec(x);
	print_vec(y);
	
	// cout << ((check_beat(x, y) == false) ? "It's OK" : "There was an error\n");

	return (0);
}