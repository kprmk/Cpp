#pragma once
#include <iostream>

template <class X>
class BaseOrderedList
{
protected:
	int lsize;
public:
	BaseOrderedList(){};
	virtual BaseOrderedList <X>& AddElement(X val) = 0;
	virtual BaseOrderedList <X>& DelElementFromHead() = 0;
	virtual BaseOrderedList <X>& DelElementFromTail() = 0;
	virtual BaseOrderedList <X>& DelElement(X val) = 0;
	virtual bool ifexist(X val) = 0;
	virtual ~BaseOrderedList(){};
	bool isempty() const
	{
	/*	if (!lsize)
			return true;
		else
			return false;*/
		return (!lsize);
	}

	virtual const X& operator [](const int Ind) const = 0;

	int size()
	{ return lsize; }

	friend std::ostream& operator <<(std::ostream& os, BaseOrderedList <X>& List)
	{
		if (!List.isempty())
		{
			for (int i = 0; i < List.lsize; i++)
			{
				os << List[i] << ' ';
			}
			os << std::endl;
			return os;
		}
	}
};