#include "List.h"
#include "Queue.h"
#include "Stack.h"

int main()
{
	//Stack<int> s;
	//std::cout << s.isEmpty() << std::endl;
	//s.push(1).push(2).push(3);
	////std::cout << s.lenght() << std::endl;
	//std::cout << s;
	//std::cout << s.peek() << std::endl;
	//s.pop();
	//std::cout << s;
	////std::cout << s.lenght() << std::endl;
	//std::cout << s.peek() << std::endl;
	//s.push(10).push(11);
	//s.peek() = 15;
	//std::cout << s;
	//std::cout << s.isEmpty() << std::endl;
	Queue<int> q;
	std::cout << q.isEmpty() << std::endl;
	std::cout << q.lenght() << std::endl;
	q.enque(1).enque(2).enque(3).enque(14);
	std::cout << q.lenght() << std::endl;
	std::cout << q.getFirst() << std::endl;
	std::cout << q.getLast() << std::endl;
	
	getchar();
	return 0;
}