#include <iostream>
using namespace std;

string Ceasar_cypher(string input)
{
	int len = input.length();
	for (int i = 0; i < len; i++)
	{
		if (input[i] >= 'z' - 9)
			input[i] -= 16;
		else
			input[i] += 10;
	}
	return (input);
}

int main()
{
	cout << Ceasar_cypher("abcdefghijklmnopqrstuvxyz") << endl;
	return (0);
}

