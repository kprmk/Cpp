#include <iostream>
#include <vector>

using namespace std;

void permut_rec(vector<int> &cur, vector<bool> &choise, int n, int &counter)
{
	if (cur.size() == n)
	{
		counter++;
		cout << counter << " <-> { ";
		for (auto it = cur.begin(); it != cur.end(); it++)
			cout << *it << " ";
		cout << "}" << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (choise[i] == true)
				continue;
			cur.push_back(i + 1);
			choise[i] = true;
			permut_rec(cur, choise, n, counter);
			cur.pop_back();
			choise[i] = false;
		}
	}
}

void permut(int amount)
{
	int counter = 0;
	vector<int> cur;
	vector<bool> choise(amount, false);
	permut_rec(cur, choise, amount, counter);
}

int main()
{
	int amount;
	cin >> amount;
	permut(amount);

	return (0);
}