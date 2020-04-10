// #include <iostream>
// #include <vector>

// using namespace std;

// void print_vec(vector<int> ipt)
// {
// 	for (auto i : ipt)
// 		cout << i << " ";
// 	cout << endl;
// }

// bool check_q(vector<int> x, vector<int> y)
// {
// 	for (int i = 0; i < x.size() - 1; i++)
// 	{
// 		for (int j = i + 1; i < x.size(); j++)
// 		{
// 			if (x[i] == x[j] || y[i] == y[j] || 
// 				abs(x[i] - x[j]) == abs(y[i] - y[j]))
// 				return (true);
// 		}
// 	}
// 	return (false);
// }

// int main()
// {
// 	int size;
// 	vector<int> x;
// 	vector<int> y;
// 	string ans;
	
// 	getline(cin, ans);
// 	size = ans[0] - '0';
// 	for (int i = 0; i < size; i++)
// 	{
// 		getline(cin, ans);
// 		x.push_back(ans[0] - '0');
// 		y.push_back(ans[2] - '0');
// 	}

// 	print_vec(x);
// 	print_vec(y);

// 	cout << (check_q(x, y) ? "There was an error\n" : "It's OK\n");

// 	return (0);
// }


#include <iostream>

class human
{
	private:

	std::string name;
	int age;

	void inside()
	{

	}

	public:

};

int main()
{
	human test;
	test.
	return (0);
}