#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include "PriorityQueue.h"
#include "graph.h"


using std::cout;
using std::endl;

void PriorityQueueDemo();
void GraphDemo();
void ReverseIteratorsDemo();
void BracketAnalyzer();

int main()
{
	//PriorityQueueDemo();
	//GraphDemo();
	//ReverseIteratorsDemo();
	BracketAnalyzer();
			
	std::cin.get();
	system("PAUSE");
    return 0;
}

void PriorityQueueDemo()
{
	//Тестирование очереди с приоритетами
	PriorityQueue<int, int> test;
	test.push(2, 3);
	test.push(2, 4);
	test.push(1, 2);
	test.push(2, 1);
	test.push(1, 1);
	while (!test.empty())
	{
		cout << test;
		test.pop();
	}
	cout << test;
}

void GraphDemo()
{
	graph<char,int> test;

	test.addEdge('b', 'm', 1);
	test.addEdge('m', 's', 2);
	test.addEdge('s', 't', 3);
	test.addEdge('t', 'u', 4);
	cout << test;

	test.removeVertex('m');
	cout << test;
}

void ReverseIteratorsDemo()
{
	std::vector<char> test;
	
	test.push_back('B');
	test.push_back('M');
	test.push_back('S');
	test.push_back('T');
	test.push_back('U');

	for (auto it = test.begin(); it != test.end(); it++)
		cout << *it;
	cout << endl;

	for (auto it = test.rbegin(); it != test.rend(); it++)
		cout << *it;
	cout << endl;
}

void BracketAnalyzer()
{
	std::string expression;
	std::cin >> expression;
	std::cin.get();

	int i = 0;
	std::stack<char> bracketStack;

	std::string openingBrackets = "([{<";
	std::string closingBrackets = ")]}>";
	//{(a + b) * <c - d>}
	//
	for (char c : expression)
	{
		if (openingBrackets.find(c) != std::string::npos)
		{
			bracketStack.push(c);
		}
		if (closingBrackets.find(c) != std::string::npos)
		{
			if (bracketStack.empty())
			{
				cout << std::string(i, '-') + '^' << endl;
				cout << "The closing bracket without opening one";
				return;
			}//{(}
			if (openingBrackets.find(bracketStack.top()) != closingBrackets.find(c))
			{
				cout << std::string(i, '-') + '^' << endl;
				cout << "The closing bracket does not match opening one";
				return;
			}
			bracketStack.pop();
		}
		i++;
	}
	
	if (!bracketStack.empty())
	{
		cout << std::string(i, '-') + '^' << endl;
		cout << "There is not enough closing brackets";
		return;
	}
	
	cout << "The correct bracket expression";
}