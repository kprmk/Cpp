#pragma once

template <typename ItemType>
class BaseQueue
{
	public:
		BaseQueue() {}
		virtual BaseQueue<ItemType>& enque(const ItemType& item) = 0;
		virtual BaseQueue<ItemType>& deque() = 0;
		virtual ItemType& getFirst() = 0;
		virtual ItemType& getLast() = 0;
		virtual const ItemType& getFirst() const = 0;
		virtual const ItemType& getLast() const = 0;
		virtual int length() const = 0;
		virtual bool isEmpty() const = 0;
		virtual ~BaseQueue() {}
};
