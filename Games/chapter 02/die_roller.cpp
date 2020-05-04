#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));  
	// seed random number generator based on current time

	int randomNumber = rand(); // generate random number

	int num = (randomNumber % 6) + 1; 
	// get a number between 1 and 6
	cout << "Your number is " << num << endl;

    return 0;
}

