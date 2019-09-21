#pragma once
#include "BaseList.h"
#include <iostream>

template <typename ItemType>
class RoundArray : public BaseList<ItemType>
{
private:
	ItemType* buf;
	int m_buf_size;
	int m_head_index;
	int m_tail_index;
	void extend();
	void reduce();
public:
	RoundArray(const int size=1);
	RoundArray(const ItemType* ItemArray, const int size);
	RoundArray(const RoundArray<ItemType>& exist);
	~RoundArray();
	virtual BaseList<ItemType>& addInHead(const ItemType& Item);
	virtual BaseList<ItemType>& addInTail(const ItemType& Item);
	virtual BaseList<ItemType>& removeFromHead();
	virtual BaseList<ItemType>& removeFromTail();
	virtual ItemType& operator[] (const int index);
	virtual const ItemType& operator[] (const int index) const;
};

template <typename ItemType>
void RoundArray<ItemType>::extend()
{
	ItemType* new_buf = new ItemType[2 * m_buf_size];
	for (int i = 0; i < m_size; i++)
		new_buf[i] = buf[(m_head_index + i) % m_buf_size];
	delete[] buf;
	buf = new_buf;
	m_head_index = 0;
	m_tail_index = m_size;
	m_buf_size = 2 * m_buf_size;
}

template <typename ItemType>
void RoundArray<ItemType>::reduce()
{
	ItemType* new_buf = new ItemType[m_buf_size / 2];
	for (int i = 0; i < m_size; i++)
		new_buf[i] = buf[(m_head_index + i) % m_buf_size];
	delete[] buf;
	buf = new_buf;
	m_head_index = 0;
	m_tail_index = m_size;
	m_buf_size = m_buf_size / 2;
}

template <typename ItemType>
RoundArray<ItemType>::RoundArray(const int size)
{
	m_buf_size = size;
	m_head_index = 0;
	m_tail_index = 0;
	m_size = 0;
	buf = new ItemType[m_buf_size];
}

template <typename ItemType>
RoundArray<ItemType>::RoundArray(const ItemType* ItemArray, const int size)
{
	m_buf_size = size;
	m_head_index = 0;
	m_tail_index = size;
	m_size = size;
	buf = new ItemType[m_buf_size];
	memcpy(buf, ItemArray, size * sizeof(ItemType));
}

template <typename ItemType>
RoundArray<ItemType>::RoundArray(const RoundArray<ItemType>& exist)
{
	m_buf_size = exist.m_buf_size;
	m_head_index = exist.m_head_index;
	m_tail_index = exist.m_tail_index;
	m_size = exist.m_size;
	buf = new ItemType[m_buf_size];
	memcpy(buf, exist.buf, m_size * sizeof(ItemType));
}

template <typename ItemType>
RoundArray<ItemType>::~RoundArray()
{
	delete[] buf;
}

template <typename ItemType>
BaseList<ItemType>& RoundArray<ItemType>::addInHead(const ItemType& Item)
{
	if (m_size == m_buf_size)
		extend();

	if (m_head_index)
		m_head_index--;
	else
		m_head_index = m_buf_size - 1;

	buf[m_head_index] = Item;
	m_size++;

	return *this;
}

template <typename ItemType>
BaseList<ItemType>& RoundArray<ItemType>::addInTail(const ItemType& Item)
{
	if (m_size == m_buf_size)
		extend();

	buf[m_tail_index % m_buf_size] = Item;

	if (m_tail_index < m_buf_size)
		m_tail_index++;
	else
		m_tail_index = 1;

	m_size++;

	return *this;
}

template <typename ItemType>
BaseList<ItemType>& RoundArray<ItemType>::removeFromHead()
{
	m_head_index = (m_head_index + 1) % m_buf_size;

	m_size--;
	if (m_size < (m_buf_size / 4))
		reduce();

	return *this;
}

template <typename ItemType>
BaseList<ItemType>& RoundArray<ItemType>::removeFromTail()
{
	if (m_tail_index)
		m_tail_index--;
	else
		m_tail_index = m_buf_size - 1;

	m_size--;
	if (m_size < (m_buf_size / 4))
		reduce();

	return *this;
}

template <typename ItemType>
ItemType& RoundArray<ItemType>::operator[](const int index)
{
	//пока без проверки
	return buf[(m_head_index + index) % m_buf_size];
}

template <typename ItemType>
const ItemType& RoundArray<ItemType>::operator[](const int index) const
{
	//пока без проверки
	return buf[(m_head_index + index) % m_buf_size];
}