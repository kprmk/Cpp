#include "BaseOrderedList.h"

template <class X>
class List : public BaseOrderedList <X>

{
private:
	struct Node
	{
		Node* next;
		X value;
	};
	Node* head;
	Node* tail;
	Node* search(X val)
	{
		Node* temp = head;
		while ((temp->value != val) && (temp->next))
		{
			temp = temp->next;
		}
		if (temp ->value == val)
		{
			return temp;
		}
		else
		{
			return nullptr;
		}
	}
	Node* toput(X val)
	{
		Node* temp = head;
		if (lsize == 1)
		{
			return head;
		}
		while (temp->next)
		{
			if ((temp->value >= val) && (temp->next->value <= val))
			{
				return temp;
			}
			temp = temp->next;

		}
		return temp;
	}
	
	void destroyNode(Node* todestroy)
	{
		if (!isempty())
		{
			if (lsize == 1)
			{
				head->next = nullptr;
				delete head;
				return;
			}
			else
			{
				Node* temp = head;
				if (todestroy == head)
				{
					head = head->next;
					delete todestroy;
					return;
				}
				while (temp->next != todestroy)
				{
					temp = temp->next;
				}
				if (todestroy == tail)
				{
					tail = temp;
				}
				
				temp->next = todestroy->next;
				delete todestroy;
				return;
			}
		}
	}
	void addAfter(X val, Node* left)
	{
		Node* newone = new Node;
		newone->value = val;
		if (left->next)
		{
			newone->next = left->next;
			left->next = newone;
			return;
		}
		else
		{
			newone->next = nullptr;
			left->next = newone;
			return;
		}
	}
	void deletelist(Node* start)
	{
		if (!isempty())
		{

			if (start->next)
			{
				deletelist(start->next);
				destroyNode(start);
			}
			destroyNode(start);
			return;
		}
	}
	
public:

	List() : BaseOrderedList <X>(){};
	BaseOrderedList <X>& AddElement(X val)
	{
		if (!isempty())
		{
			if (val > head->value)
			{
				Node* newone = new Node;
				newone->value = val;
				newone->next = head;
				head = newone;
				lsize++;
				return *this;
			}
			if (val < tail->value)
			{
				Node* newone = new Node;
				newone->value = val;
				tail->next = newone;
				newone->next = nullptr;
				tail = newone;
				lsize++;
				return *this;
			}
			Node* temp = toput(val);
			addAfter(val, temp);
			lsize++;
			if (temp == tail)
			{
				tail = tail->next;
			}
			return *this;
			
		}
		else
		{
			Node* newone = new Node;
			newone->value = val;
			head = newone;
			tail = head;
			lsize++;
			return *this;
		}
	}
	
	BaseOrderedList <X>& DelElementFromHead()
	{
		if (!isempty())
		{
			if (lsize == 1)
			{
				destroyNode(head);
				lsize--;
				return *this;
			}

			destroyNode(head);
			lsize--;
			return *this;
		}
		else
		{
			return *this;
		}
	}
	BaseOrderedList <X>& DelElementFromTail()
	{
		if (!isempty())
		{
			if (lsize == 1)
			{
				destroyNode(head);
				lsize--;
				return *this;
			}

			
			destroyNode(tail);
			lsize--;
			return *this;
		}
		else
		{
			return *this;
		}
	}

	BaseOrderedList <X>& DelElement(X val)
	{
		if (!isempty())
		{

			while (search(val))
			{
				destroyNode(search(val));
				lsize--;
			}
			
		}
		return *this;
	}
	bool ifexist(X val)
	{
		return (search(val));
	}
	const X& operator [](const int Ind) const
	{
		if (!isempty())
		{
			Node* temp = head;
			int i = 0;
			for (i; i < Ind; i++)
			{
				temp = temp->next;
			}
			return temp->value;
		}
		
	}
	

	~List()
	{
		deletelist(head);
	}

};