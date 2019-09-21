#pragma once

#include "BaseList.h"

template <typename T>
class List : public BaseList<T>
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	};

	Node *head, *tail;

	Node* buildNode(T value, Node* left, Node* right)
	{
		Node* newNode = new Node;
		newNode->data = value;
		newNode->prev = left;
		newNode->next = right;
		if (left)
		{
			left->next = newNode;
		}
		if (right)
		{
			right->prev = newNode;
		}
		return newNode;
	}
	void destroyNode(Node* node)
	{
		if (node->next)
		{
			node->next->prev = node->prev;
			node->next = nullptr;
		}
		if (node->prev)
		{
			node->prev->next = node->next;
			node->prev = nullptr;
		}
		/*node->prev->next = node->next;
		node->next->prev = node->prev;
		node->next = nullptr;
		node->prev = nullptr;*/
		delete node;
	}
	Node* addAfter(T value, Node* node)	{ return buildNode(value, node, node->next); }
	Node* addBefore(T value, Node* node)	{ return buildNode(value, node->prev, node); }
public:
	List() : head(nullptr), tail(nullptr)	{}
	~List()	{}
	BaseList<T>& addInHead(T value)
	{
		Node* newNode;
		if (head)
		{
			newNode = addBefore(value, head);
		}
		else
		{
			newNode = buildNode(value, nullptr, nullptr);
			tail = newNode;
		}
		head = newNode;
		Lsize++;
		return *this;
	}
	BaseList<T>& addInTail(T value)
	{
		Node* newNode;
		if (head)
		{
			newNode = addAfter(value, tail);
		}
		else
		{
			newNode = buildNode(value, nullptr, nullptr);
			head = newNode;
		}
		tail = newNode;
		Lsize++;
		return *this;
	}
	BaseList<T>& removeFromHead()
	{
		Node* temp = head->next;
		destroyNode(head);
		head = temp;
		Lsize--;
		return *this;
	}
	BaseList<T>& removeFromTail()
	{
		Node* temp = tail->prev;
		destroyNode(tail);
		tail = temp;
		Lsize--;
		return *this;
	}
	T& operator[] (int i)
	{	
		Node* temp = head;
		for (int j = 0; j < i; j++)
		{
			temp = temp->next;
		}
		return temp->data;
	}
	const T operator[]	(int i)const
	{
		Node* temp = head;
		for (int j = 0; j < i; j++)
		{
			temp = temp->next;
		}
		return temp->data;
	}
};