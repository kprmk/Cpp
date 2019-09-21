#pragma once
#include <cstdio>

template <typename T>
struct Node 
{
	T data;
	struct Node* next;
};

template <typename T>
class List
{
private:

	struct Node<T>* head;
	struct Node<T>* tail;

	struct Node<T>** getL()
	{
		struct Node<T>** all = 
		struct Node<T>* temp = a;
		for (; temp->next != b; temp = temp->next);
		return temp;
	}

public:
	List();
	List(T now);
	~List();

	void pushInHead(T value);
	void pushInTail(T value);

	void popFromHead();
	void popFromTail();

	T peekFromHead();
	T peekFromTail();

	void deleteList();

	void printListFromHead();
	void printListFromTail();
};
template <typename T>
List<T>::List(T now)
{
	struct Node<T>* it = new struct Node<T>;
	it->data = now;
	head = it;
	tail = it;
	tail->next = nullptr;
}

template <typename T>
List<T>::List()
{
	 struct Node<T>* it = new struct Node<T>;
	it->date = nullptr;
	head = it;
	tail = it;
	tail->next = nullptr;
}

template <typename T>
List<T>::~List()
{

}

template <typename T>
void List<T>::pushInHead(T value)
{
	if (head)
	{
		struct Node<T>* item = new struct Node<T>;
		//head->next = item;
		item->data = value;
		item->next = head;
		head = item;
	}
}

template <typename T>
void List<T>::pushInTail(T value)
{
	struct Node<T>* item = new struct Node<T>;
	item->data = value;
	item->next = nullptr;
	tail->next = item;
	tail = item;
}

template <typename T>
void List<T>::popFromHead()
{
	if (head)
	{
		struct Node<T>* temp = head;
		/*struct Node<T>* a = tail;*/
		head = head->next;
		delete temp;
		/*delete a;*/
	}
}

template <typename T>
void List<T>::popFromTail()
{
	struct Node<T>* temp;
	for (temp = head; temp->next != tail; temp = temp->next);
	delete tail;
	tail = temp;
	temp->next = nullptr;
}

template <typename T>
T List<T>::peekFromHead()
{
	if (head)
	{
		struct Node<T>* temp = head;
		T r = head->data;
		head = head->next;
		delete temp;
		return r;
	}
	else
		return nullptr;
}

template <typename T>
T List<T>::peekFromTail()
{
	if (head != tail)
	{
		struct Node<T>* temp = head;
		for (; temp->next != tail; temp = temp->next);
		T a = tail->data;
		tail = temp;
		tail->next = nullptr;
		delete temp;
		return a;
	}
	else
	{
		T a = head->data;
		//delete list must be here~!!!!
		return a;
	}
	
}

template <typename T>
void List<T>::deleteList()
{
	
}

template <typename T>
void List<T>::printListFromHead()
{
	struct Node<T> * temp = head;
	while (temp)
	{
		std::cout << temp->data << ' ';
		temp = temp->next;
	}
	std::cout << std::endl;
}

template <typename T>
void List<T>::printListFromTail()
{
	struct Node<T> * temp;
	std::cout << tail->data << ' ';
	do
	{
		temp = this.returnT();
		std::cout << temp->data << ' ';
	}
	while()
}