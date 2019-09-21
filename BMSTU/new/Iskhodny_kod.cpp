#include "List.h"
#include <cstdio>

void main()
{
	List<int> Test;
	Test.AddElement(2).AddElement(6).AddElement(10).AddElement(1).AddElement(2134).AddElement(1).AddElement(4).AddElement(2).AddElement(4).AddElement(7);
	std::cout << Test;
	Test.DelElement(2).DelElementFromHead().DelElementFromTail();
	std::cout << Test;
	



	getchar();
}