#pragma once
#include "BaseList.h"

template <typename ItemType>
class LinkedList : public BaseList<ItemType>
{
	private:
		struct ListNode
		{
			ItemType data;
			ListNode *next;
			ListNode *prev;
		};

		ListNode* buildNode(const ItemType& value, 
			ListNode *left = nullptr, 
			ListNode *right = nullptr)
		{
			ListNode *newNode = new ListNode;
			newNode->next = right; 
			newNode->prev = left;
			newNode->data = value;
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
		ListNode* addAfter(const ItemType& value, ListNode *node)
		{
			return buildNode(value, node, node->next);
		}
		ListNode* addBefore(const ItemType& value, ListNode *node)
		{
			return buildNode(value, node->prev, node);
		}
		void remove(ListNode *node)
		{
			if (node)
			{
				if (node->next)
				{
					node->next->prev = node->prev;
				}
				if (node->prev)
				{
					node->prev->next = node->next;
				}

				node->next = node->prev = nullptr;
				delete(node);
			}
		}
	
		ListNode* m_pHead;
		ListNode* m_pTail;

	public:
		LinkedList();
		virtual BaseList<ItemType>& addInHead(const ItemType& Item);
		virtual BaseList<ItemType>& addInTail(const ItemType& Item);
		virtual BaseList<ItemType>& removeFromHead();
		virtual BaseList<ItemType>& removeFromTail();
		virtual ItemType& operator[](const int index);
		virtual const ItemType& operator[](const int index) const;
		virtual ~LinkedList();
};

template <typename ItemType>
LinkedList<ItemType>::LinkedList()
{
	m_pHead = m_pTail = nullptr;
	m_size = 0;
}

template <typename ItemType>
BaseList<ItemType>& LinkedList<ItemType>::addInHead(const ItemType& Item)
{
	if (m_size)
	{
		m_pHead = addBefore(Item, m_pHead);
	}
	else
	{
		m_pHead = m_pTail = buildNode(Item);
	}
	m_size++;

	return *this;
}

template <typename ItemType>
BaseList<ItemType>& LinkedList<ItemType>::addInTail(const ItemType& Item)
{
	if (m_size)
	{
		m_pTail = addAfter(Item, m_pTail);
	}
	else
	{
		m_pHead = m_pTail = buildNode(Item);
	}
	m_size++;

	return *this;
}

template <typename ItemType>
BaseList<ItemType>& LinkedList<ItemType>::removeFromHead()
{
	switch (m_size)
	{
		case 0: 
			return *this;
		case 1:
			remove(m_pHead);
			m_pHead = m_pTail = nullptr;
			break;
		default:
			ListNode* temp = m_pHead;
			m_pHead = m_pHead->next;
			remove(temp);
	}
	
	m_size--;
	
	return *this;
}

template <typename ItemType>
BaseList<ItemType>& LinkedList<ItemType>::removeFromTail()
{
	switch (m_size)
	{
		case 0: 
			return *this;
		case 1:
			remove(m_pHead);
			m_pHead = m_pTail = nullptr;
			break;
		default:
			ListNode* temp = m_pTail;
			m_pTail = m_pTail->prev;
			remove(temp);
	}

	m_size--;

	return *this;
}

template <typename ItemType>
ItemType& LinkedList<ItemType>::operator[](const int index)
{
	// Не реализована проверка на выход индекса за пределы [0, m_size - 1]

	ListNode *temp = nullptr;
	int i;

	if (index < m_size / 2)
	{
		temp = m_pHead;
		i = 0;

		while (i++ < index)
		{
			temp = temp->next;
		}
	}
	else
	{
		temp = m_pTail;
		i = m_size - 1;

		while (i-- > index)
		{
			temp = temp->prev;
		}
	}

	return temp->data;
}

template <typename ItemType>
const ItemType& LinkedList<ItemType>::operator[](const int index) const
{
	// Не реализована проверка на выход индекса за пределы [0, m_size - 1]

	ListNode *temp = nullptr;
	int i;

	if (index < m_size / 2)
	{
		temp = m_pHead;
		i = 0;

		while (i++ < index)
		{
			temp = temp->next;
		}
	}
	else
	{
		temp = m_pTail;
		i = m_size - 1;

		while (i-- > index)
		{
			temp = temp->prev;
		}
	}

	return temp->data;
}

template <typename ItemType>
LinkedList<ItemType>::~LinkedList()
{
	while (m_size)
	{
		remove(m_pHead);
	}
}