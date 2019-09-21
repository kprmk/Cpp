#pragma once

template <typename ItemType>
class BaseStack
{
	public:
		BaseStack() {}
		virtual BaseStack<ItemType>& push(const ItemType& item) = 0;
		virtual BaseStack<ItemType>& pop() = 0;
		virtual ItemType& peek() = 0;
		virtual const ItemType& peek() const = 0;
		virtual int length() const = 0;
		virtual bool isEmpty() const = 0;
		virtual ~BaseStack() {}
};

