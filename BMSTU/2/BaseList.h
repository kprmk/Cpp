#pragma once
#include <iostream>

template <typename ItemType>
class BaseList
{
	protected:
		int m_size;

	public:
		BaseList(){}
		const int size() const
		{
			return m_size;
		}
		const bool isEmpty() const
		{
			return (m_size ? false : true);
		}
		virtual BaseList<ItemType>& addInHead(const ItemType& Item) = 0;
		virtual BaseList<ItemType>& addInTail(const ItemType& Item) = 0;
		virtual BaseList<ItemType>& removeFromHead() = 0;
		virtual BaseList<ItemType>& removeFromTail() = 0;
		virtual ItemType& operator[](const int index) = 0;
		virtual const ItemType& operator[](const int index) const = 0;
		virtual ~BaseList() {}
	
		template <typename ItemType>
		friend std::ostream& operator<<(std::ostream& os, const BaseList<ItemType>& list);
};

template <typename ItemType>
std::ostream& operator<<(std::ostream& os, const BaseList<ItemType>& list)
{
	for (int i = 0; i < list.m_size; i++)
	{
		os << list[i] << " ";
	}
	os << std::endl;
	return os;
}
