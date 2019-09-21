#pragma once
#include <iostream>

template <typename T>
class LinkedList
{
	protected:
		struct ListNode
		{
			T value;
			ListNode *next;
		};

		void printNode(ListNode *node, bool reverse = false) const
		{
			if (reverse)
			{
				if (node->next)
				{
					printNode(node->next, reverse);
				}
			}
			std::cout << node->value << ' ';
			if (!reverse)
			{
				if (node->next)
				{
					printNode(node->next, reverse);
				}
			}
		}
		void deleteNodes(ListNode *node) 
		{
			if (node)
			{
				if (node->next)
				{
					deleteNodes(node->next);
				}
				delete(node);
			}
		}
		
		ListNode *head;
		ListNode *tail;

	public:
		LinkedList() : head(nullptr), tail(nullptr) {}
		LinkedList(T value) { head = new ListNode; head->value = value; head->next = nullptr; tail = head; }
		~LinkedList();

		void addInHead(T value);
		void addInTail(T value);
		void deleteFromHead();
		void deleteFromTail();
		bool isEmpty() const { return (bool)head; }
		T peekHead() const { return head->value; }
		T peekTail() const { return tail->value; }
		void printList(bool reverse = false) const;
		void clear() { tail = nullptr; deleteNodes(head); head = nullptr; }
};

//template <typename T>
//LinkedList<T>::LinkedList(LinkedList<T> &list)
//{
//	if (list == *this)
//	{
//		return;
//	}
//
//	if (list.head)
//	{
//		this->head = new ListNode;
//		this->head->value = list.head->value;
//		
//		ListNode temp = list.head->next;
//		if (temp)
//		{
//			this->
//		}
//	}
//}

template <typename T>
LinkedList<T>::~LinkedList()
{
	deleteNodes(head);
}

template <typename T>
void LinkedList<T>::addInHead(T value)
{
	ListNode *newNode = new ListNode;
	newNode->value = value;
	newNode->next = head;
	head = newNode;
	if (!tail)
	{
		tail = head;
	}
}

template <typename T>
void LinkedList<T>::addInTail(T value)
{
	ListNode *newNode = new ListNode;
	newNode->value = value;
	newNode->next = nullptr;
	if (tail)
	{
		tail->next = newNode;
	}
	tail = newNode;
	if (!head)
	{
		head = tail;
	}
}

template <typename T>
void LinkedList<T>::deleteFromHead()
{
	ListNode *temp = head;
	head = head->next;
	temp->next = nullptr;
	delete(temp);
	if (!head && tail)
	{
		tail = nullptr;
	}
}

template <typename T>
void LinkedList<T>::deleteFromTail()
{
	if (tail == head)
	{
		delete(tail);
		head = nullptr;
		tail = nullptr;
		return;
	}

	ListNode *temp = head;
	while (temp->next != tail)
	{
		temp = temp->next;
	}
	tail = temp;
	delete(tail->next);
	tail->next = nullptr;
}

template <typename T>
void LinkedList<T>::printList(bool reverse) const
{
	if (!head)
	{
		std::cout << "Empty!" << std::endl;
		return;
	}
	printNode(head, reverse);
	std::cout << std::endl;
}
