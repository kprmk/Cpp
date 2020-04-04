#include <iostream>
#include <vector>

using namespace std;


void permutation_inside(vector<int> *vec, vector<bool> *is_empty, int n, int *c)
{
	if (vec->size() == n)
	{
		(*c)++;
		cout << *c << " -> { ";
		for (auto i : *vec)
			cout << i << " ";
		cout << "}" << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if ((*is_empty)[i] == true)
				continue;
			(*is_empty)[i] = true;
			(*vec).push_back(i + 1);
			permutation_inside(vec, is_empty, n, c);
			(*is_empty)[i] = false;
			vec->pop_back();
		}
	}
}

void permutation(int n)
{
	int counter = 0;
	vector<int> vec;
	vector<bool> is_empty(n, false);
	// start recursion
	permutation_inside(&vec, &is_empty, n, &counter);
}

int main()
{
	int size;
	cin >> size;
	permutation(size);
    return (0);
}