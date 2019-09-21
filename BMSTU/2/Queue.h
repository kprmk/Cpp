#pragma once
#include "BaseQueue.h"
#include "LinkedList.h"

template <typename ItemType>
class Queue : public BaseQueue<ItemType>, private LinkedList<ItemType>
{
	public:
		Queue() : LinkedList<ItemType> () {};
		virtual BaseQueue<ItemType>& enque(const ItemType& item)
		{
			addInTail(item);
			return *this;
		}
		virtual BaseQueue<ItemType>& deque()
		{
			removeFromHead();
			return *this;
		}
		virtual ItemType& getFirst()
		{
			//пока без проверки на пустоту
			return LinkedList<ItemType>::operator[](0);
		}
		virtual ItemType& getLast()
		{
			//пока без проверки на пустоту
			return LinkedList<ItemType>::operator[](m_size-1);
		}
		virtual const ItemType& getFirst() const
		{
			//пока без проверки на пустоту
			return LinkedList<ItemType>::operator[](0);
		}
		virtual const ItemType& getLast() const
		{
			//пока без проверки на пустоту
			return LinkedList<ItemType>::operator[](m_size-1);
		}
		virtual int length() const
		{
			return size();
		}
		virtual bool isEmpty() const
		{
			return LinkedList<ItemType>::isEmpty();
		}
		virtual ~Queue() {};
};