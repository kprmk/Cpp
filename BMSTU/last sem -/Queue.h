#pragma once 

#include "BaseQueue.h"
#include "List.h"

template <typename T>
class Queue : public BaseQueue<T>, private List<T>
{
public:
	Queue(){}
	~Queue(){}

	BaseQueue<T>& enque(T a)
	{
		/*Node* A;
		A = new[T];
		if (!isEmpty())
			A->next = head;
		head = A;
		A.data = a;
		return *this;*/
		addInHead(a);
		return *this;
	};

	BaseQueue<T>& deque()
	{
		/*if (tail = nullptr)
			head-> = nullptr;
		tail = tail->prev;
		tail->next = nullptr;
		return *this;*/
		removeFromTail();
		return *this;
	};

	T& getFirst()	{ return (*this)[this->lenght() - 1]; }
	const T& getFirst()const	{ return (*this)[this->lenght() - 1]; }
	T& getLast()	{ return (*this)[0]; }
	const T& getLast() const	{ return (*this)[0]; }
	bool isEmpty()const	{ return !size(); }
	int lenght()const	{ return size(); }
};