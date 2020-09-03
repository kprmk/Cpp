#include <iostream>
using namespace std;

#define BLUE "\033[36m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define PURPLE "\033[35m"
#define YELLOW "\033[33m"
#define BOLD "\033[1m"
#define UNDER "\033[4m"
#define RED_BACK "\033[41m"
#define YELLOW_BACK "\033[43m"
#define BLUE_BACK "\033[46m"
#define RESET "\033[0m"

int main()
{
	// cout << BLUE << UNDER << RED_BACK << "HELLO" << RESET << endl;
	cout << PURPLE << UNDER << YELLOW_BACK << "##################" << RESET << endl;

    return 0;
}