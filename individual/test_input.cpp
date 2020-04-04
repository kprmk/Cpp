#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void check_border();

int main()
{
	srand(time(0));
	int COUNTER = 1;
	//constant  - постоянный, неизменный
	const int input = 8;
	for (int i = 0; i < 10; i++)
	{
		cout << rand() << endl;
	}
    return (0);
}