#pragma once

#include "BaseStack.h"
#include "List.h"

template <typename T>
class Stack : public BaseStack<T>
{
protected:
	List<T> list;
public:
	Stack() {}
	~Stack() {}

	BaseStack<T>& push(const T& value)
	{ 
		list.addInHead(value); 
		return *this;
	}
	BaseStack<T>& pop()
	{ 
		list.removeFromHead(); 
		return *this;
	}
	const T& peek() const	{return list[0];}
	T& peek() { return list[0]; }
	bool isEmpty() const { return  list.isEmpty(); }
	int lenght()const	{ return  list.size(); }
	friend std::ostream& operator<<(std::ostream& os, const Stack<T>& obj)
	{
		return (os << obj.list);
	}
};