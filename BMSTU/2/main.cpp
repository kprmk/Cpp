// Inheritance.cpp: определяет точку входа для консольного приложения.

#include "Stack.h"
#include "Queue.h"
#include <iostream>

int main()
{
	std::cout << "class Stack testing" << std::endl;
	Stack<int> test_stack;
	test_stack.push(1).push(2).push(3).push(4);
	while (!test_stack.isEmpty())
	{
		std::cout << test_stack.peek() << " ";
		test_stack.pop();
	}
	std::cout << std::endl;

	std::cout << "class Queue testing" << std::endl;
	Queue<int> test_queue;
	test_queue.enque(1).enque(2).enque(3).enque(4);
	while (!test_queue.isEmpty())
	{
		std::cout << test_queue.getFirst() << " ";
		test_queue.deque();
	}
	std::cout << std::endl;
	
	std::cin.get();
	return 0;
}

