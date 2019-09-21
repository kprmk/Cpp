#pragma once
#include "stdafx.h"
#include <iostream>
 
template <class T>
class BaseQueue
{
public:
	BaseQueue(){};
	virtual ~BaseQueue(){};
	virtual BaseQueue<T>& enque(T a) = 0;
	virtual BaseQueue<T>& deque() = 0;
	virtual T& getFirst() = 0;
	virtual const T& getFirst()const = 0;
	virtual T& getLast() = 0;
	virtual const T& getLast() const = 0;
	virtual bool isEmpty()const = 0;
	virtual int lenght()const = 0;
};
