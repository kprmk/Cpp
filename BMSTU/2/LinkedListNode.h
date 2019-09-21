#pragma once

template <typename ItemType>
class LinkedListNode
{
	private:
		LinkedListNode<ItemType>* next;
		LinkedListNode<ItemType>* prev;
		
		LinkedListNode(const ItemType& value,
			LinkedListNode<ItemType>* nextNode,
			LinkedListNode<ItemType>* prevNode)
			: data(value), next(nextNode), prev(prevNode)
		{
			if (nextNode)
				nextNode->prev = this;
			if (prevNode)
				prevNode->next = this;
		}

	public:
		ItemType data;
		LinkedListNode(const ItemType& value) : data(value)
		{
			next = prev = nullptr;
		}
		LinkedListNode<ItemType>* addAfter(const ItemType& value)
		{
			return new LinkedListNode<ItemType>(value, this->next, this);
		}
		LinkedListNode<ItemType>* addBefore(const ItemType& value)
		{
			return new LinkedListNode<ItemType>(value, this, this->prev);
		}
		LinkedListNode<ItemType>* operator[] (const int index)
		{
			int i = index;
			LinkedListNode<ItemType>* pointer = this;
			if (i >= 0)
				while (i-- && pointer->next)
					pointer = pointer->next;
			else
				while (i++ && pointer->prev)
					pointer = pointer->prev;
			return pointer;
		}
		void remove()
		{
			if (next)
				next->prev = prev;
			if (prev)
				prev->next = next;
		
			next = prev = nullptr;
			delete this;
			//~LinkedListNode<ItemType>();
		}

		~LinkedListNode()
		{
			if (next)
				delete next;
			if (prev)
				delete prev;
		}
};

