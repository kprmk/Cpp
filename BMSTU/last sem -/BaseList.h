#pragma once
#include <iostream>
#include "stdafx.h"

template <typename T>
class BaseList
{
protected:
	int Lsize;
public:
	BaseList()	{};
	virtual ~BaseList()	{};

	virtual BaseList<T>& addInHead(T value) = 0;
	virtual BaseList<T>& addInTail(T value) = 0;
	virtual BaseList<T>& removeFromHead() = 0;
	virtual BaseList<T>& removeFromTail() = 0;
	int size()const	{ return Lsize; }
	bool isEmpty()const	{ return !Lsize; }
	virtual T& operator[] (int i) = 0;
	virtual const T operator[]	(int i)const = 0;
	template <typename T>
	friend std::ostream& operator<<(std::ostream& os, const BaseList<T>& obj)
	{
		for (int i = 0; i < obj.size(); i++)
		{
			os << obj[i] << "; ";
		}
		os << std::endl;
		return os;
	}
};