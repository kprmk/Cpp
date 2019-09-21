#pragma once
#include "LinkedList.h"

template <typename T>
class Stack
{
	private:
		LinkedList<T> list;

	public:
		Stack() : list() {}
		Stack(T value) : list(value) {}
		~Stack() {}

		void push(T value) { list.addInHead(value); }
		void pop() { list.deleteFromHead(); }
		T peek() const { return list.peekHead(); }
		void print() const { list.printList(); }
		void clear() { list.clear(); }
		bool isEmpty() const { return list.isEmpty(); }
};

template <typename T>
class Queue : private LinkedList<T>
{
	public:
		Queue() : head(nullptr), tail(nullptr) {}
		Queue(T value) { head = new ListNode; head->value = value;
		head->next = nullptr; tail = head; }
		~Queue() {}

		void enter(T value) { addInTail(value); }
		void depart() { deleteFromHead(); }
		T peek() const { return peekHead(); }
		void print() const { printList(); }
		using LinkedList<T>::clear;
		using LinkedList<T>::isEmpty;
};