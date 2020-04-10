#include <iostream>
#include "human.h"

struct node
{
	int data;
	node *next;
};

int main()
{
	node first;
	node second;
	node third;

	first.data = 1;
	second.data = 2;
	third.data = 3;
	
	first.next = &second;
	second.next = &third;
	third.next = NULL;

	node *temp = &first;
	while (temp != NULL)
	{
		cout << (*temp).data << endl;
		temp = (*temp).next;
	}

	return (0);
}