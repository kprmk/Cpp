#include "LinkedList.h"
#include "SQ.h"

int main()
{
	LinkedList<int> list;
	
	list.addInHead(1);
	list.addInTail(2);
	list.addInHead(3);
	list.addInTail(4);
	
	list.printList();
	list.printList(true);

	list.deleteFromHead();
	list.deleteFromTail();
	list.deleteFromTail();
	list.deleteFromHead();

	list.printList();

	Stack<char> st1, st2('U');

	st2.push('T');
	st2.push('S');
	st2.push('M');
	st2.push('B');

	std::cout << st2.peek() << std::endl;
	st2.print();

	st2.pop();
	st2.pop();
	st2.print();

	st2.clear();
	st2.print();

	Queue<int> q(5);
	
	q.enter(2);
	q.enter(-1);
	q.enter(7);
	q.enter(4);

	q.print();

	q.depart();
	q.depart();

	q.print();

	q.clear();
	q.print();

	std::cin.get();
	return 0;
}