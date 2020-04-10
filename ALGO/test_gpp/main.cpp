#include "ceasar.h"

int main()
{
	ceasar test1 = ceasar();
	ceasar test2 = ceasar("abc", 29);
	cout << test2.getter() << endl;
	test2.to_code();
	cout << test2.getter() << endl;

	return 0;
}
