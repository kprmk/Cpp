#include "BinaryTree.h"

int main()
{
	BinaryTree bt;

	binaryTreeInit(&bt);

	insertInBT(&bt, 5);
	insertInBT(&bt, 2);
	insertInBT(&bt, 7);
	insertInBT(&bt, 6);
	insertInBT(&bt, 8);
	insertInBT(&bt, 4);
	insertInBT(&bt, 3);
	insertInBT(&bt, 1);
	insertInBT(&bt, 6);

	printTree(&bt);
	printReverseTree(&bt);

	printf("Min node: %d, max node: %d\n\n", getMinBTNode(&bt)->key, getMaxBTNode(&bt)->key);

	removeFromBT(&bt, 8);
	printTree(&bt);

	removeFromBT(&bt, 4);
	printTree(&bt);

	removeFromBT(&bt, 5);
	printTree(&bt);

	deleteTree(&bt);

	getchar();
	return 0;
}