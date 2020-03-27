#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

string mix(string input)
{
	char temp;

	for(int first_let, second_let, i = 0; i < input.length() / 2; i++)
	{
		first_let = rand() % input.length();
		second_let = rand() % input.length();

		temp = input[first_let];
		input[first_let] = input[second_let];
		input[second_let] = temp;
	}
	return input;
}

int main()
{
	srand(time(0));
	cout << mix("123456789") << endl;
    return (0);
}