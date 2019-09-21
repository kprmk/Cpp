#include "BinaryTree.h"

int main()
{
	BinaryTree<int> bt;

	bt.insert(5);
	bt.insert(2);
	bt.insert(10);
	bt.insert(-7);
	bt.insert(4);
	bt.insert(6);
	bt.insert(12);
	bt.insert(9);
	bt.insert(3);
	bt.insert(0);
	bt.insert(-9);

	std::cout << bt << std::endl;
	std::cout << std::boolalpha << bt.find(13) << ' ' << bt.find(6) << std::endl;
	std::cout << bt.maxKey() << ' ' << bt.minKey() << std::endl;
	bt.reversePrint();

	bt.remove(0);
	bt.remove(4);
	bt.remove(6);
	bt.remove(5);

	std::cout << bt << std::endl;

	bt.clear();
	std::cout << bt << std::endl;

	std::cin.get();
	return 0;
}