#pragma once
#include "stdafx.h"
#include <iostream>

template <typename T>
class BaseStack
{
public:
	BaseStack(){};
	virtual ~BaseStack(){};
	virtual BaseStack<T>& push(const T &) = 0;
	virtual BaseStack<T>& pop() = 0;
	virtual const T& peek()const = 0;
	virtual T& peek() = 0;
	virtual bool isEmpty()const = 0;
	virtual int lenght()const = 0;
};