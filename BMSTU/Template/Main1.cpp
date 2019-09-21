#include "Sort.h"
#include "List.h"
#include <cstdio>

int main()
{

	std::cout << "$\n" << std::endl;
	List<int> a(100);
	List<char> ch('Q');
	List<char*> str("QWERTY");
	std::cout << "$\n" << std::endl;

	a.pushInHead(10);
	a.pushInTail(1000);

	ch.pushInHead('A');
	ch.pushInTail('B');

	/*a.popFromHead();

	std::cout << a.peekFromTail() << std::endl;
	std::cout << ch.peekFromTail() << std::endl;
	std::cout << str.peekFromTail() << std::endl;*/

	/*ch.popFromHead();
	str.popFromHead();*/

	a.printListFromHead();
	ch.printListFromHead();

	a.printListFromTail();
	ch.printListFromTail();


	std::cin.get();
	return 0;
}