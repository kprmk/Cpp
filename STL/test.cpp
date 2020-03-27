#include <iostream>
using namespace std;

struct node 
{
	int value;
	node *next;
};

int main()
{
	node first;
	first.value = 700;
	
	node second;
	second.value = 100;

	first.next = &second;

	node *pointer_list;
	pointer_list = &first;
	cout << pointer_list->value << endl;
	cout << pointer_list->next->value << endl;


    return (0);
}
