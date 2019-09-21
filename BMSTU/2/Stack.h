#pragma once
#include "BaseStack.h"
#include "LinkedList.h"

template <typename ItemType>
class Stack : public BaseStack<ItemType>
{
	private:
		LinkedList<ItemType> list;

	public:
		Stack() {}
		virtual BaseStack<ItemType>& push(const ItemType& item)
		{
			list.addInTail(item);
			return *this;
		}
		virtual BaseStack<ItemType>& pop()
		{
			list.removeFromTail();
			return *this;
		}
		virtual ItemType& peek()
		{
			//пока без проверки, что стек пуст
			return list[length() - 1];
		}
		virtual const ItemType& peek() const
		{
			//пока без проверки, что стек пуст
			return list[length()-1];
		}
		virtual int length() const
		{
			return list.size();
		}
		virtual bool isEmpty() const
		{
			return list.isEmpty();
		}
		virtual ~Stack() {}
};

