#pragma once
#include <iostream>
#include <queue>
#include <map>

using std::map;
using std::queue;
using std::ostream;
using std::endl;


template <typename PriorityType, typename ItemType>
class PriorityQueue
{
private:
	typedef queue<ItemType> Queue;
	map<PriorityType, Queue> content;
	
public:
	PriorityQueue()	{}
	void push(const PriorityType& priority, const ItemType& item)
	{
		content[priority].push(item);
	}
	bool empty() const
	{
		return content.empty();
	}
	ItemType& front()
	{// for (std::const_iterator it = content.begin(); it != content.end(); ++it)
	// iterator: first = key; second = value;	
		return content.begin()->second.front();
	}
	const ItemType& front() const
	{
		return content.begin()->second.front();
	}
	void pop()
	{
		//вместо auto можно было бы записать map<PriorityType, Queue>::iterator
		auto it = content.begin();
		it->second.pop();
		if (it->second.empty())
			content.erase(it);
	}
	void clear()
	{
		/*for (auto& it : content) {
			delete it->second;
		}*/
		content.clear();
	}
	~PriorityQueue() {}

	template <typename PriorityType, typename ItemType>
	friend ostream& operator<< (ostream& os, const PriorityQueue<PriorityType, ItemType>& obj);
};

template <typename PriorityType, typename ItemType>
ostream& operator<< (ostream& os, const PriorityQueue<PriorityType, ItemType>& obj)
{
	if (!obj.empty())
	{
		/*
		//цикл на основе итераторов
		for (auto it = obj.content.begin(); it != obj.content.end(); it++)
		{
			os << "Priority level " << it->first << ":\t";
			queue<ItemType> temp(it->second);
			while (!temp.empty())
			{
				os << temp.front() << " ";
				temp.pop();
			}
			os << endl;
		}
		*/

		//цикл на основе диапазона
		//маскирует обращение к begin() и end()
		for (auto& elem : obj.content)
		{
			os << "Priority level " << elem.first << ":\t";
			queue<ItemType> temp(elem.second);
			while (!temp.empty())
			{
				os << temp.front() << " ";
				temp.pop();
			}
			os << endl;
		}

		os << endl;
	}
	else
		os << "The queue is empty" << endl;

	return os;
}

