#include <stdio.h>
#include <stdlib.h>

/**
*	@enum Варианты направления обхода бинарного дерева
*/
enum Direction
{
	LeftCenterRight, ///< Лево - центр - право
	RightCenterLeft, ///< Право - центр - лево
	LeftRightCenter, ///< Лево - право - центр
	RightLeftCenter, ///< Право - лево - центр
	CenterLeftRight, ///< Центр - лево - право
	CenterRightLeft ///< Центр - право - лево
};

/**
*	@struct Узел бинарного дерева
*/
typedef struct BinaryTreeNode
{
	BinaryTreeNode *left; /// @property Указатель на левого потомка
	BinaryTreeNode *right; /// @property Указатель на правого потомка
	int key; /// @property Значение, хранящееся в узле
} BinaryTreeNode;

/**
*	@struct Базовая структура бинарного дерева
*/
typedef struct
{
	BinaryTreeNode *root; /// @property Корневой узел бинарного дерева
	unsigned nodeNum; /// @property Количество элементов в бинарном дереве
} BinaryTree;

/**
*	@fn Создание узла бинарного дерева
*
*	@param key Значение, помещаемое в узел бинарного дерева
*	@return newNode Указатель на новый узел бинарного дерева
*/
BinaryTreeNode* buildNode(int key)
{
	BinaryTreeNode *newNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

/**
*	@fn Вставка элемента в бинарное поддерево
*
*	@param node Проверяемый узел бинарного поддерева
*	@param key Вставляемый элемент
*	@return (unsigned) В случае удачной вставки элемента - 1, в случае неудачи - 0
*/
unsigned insertNode(BinaryTreeNode *node, int key)
{
	// Проверяемый узел не существует (пример: пустое дерево)
	if (!node)
	{
		return 0;
	}

	// Входящее значение совпадает со значением в проверяемом узле
	if (node->key == key)
	{
		return 0;
	}
	// Входящее значение меньше того, что лежит в проверяемом узле
	else if (key < node->key)
	{
		// Потомок слева существует - перезапускаем алгоритм с указателем на него
		if (node->left)
		{
			return insertNode(node->left, key);
		}

		// Потомка слева нет - создаем новый узел и вставляем в качестве потомка слева
		node->left = buildNode(key);
		return 1;
	}
	// Входящее значение больше того, что лежит в проверяемом узле
	else
	{
		// Потомок справа существует - перезапускаем алгоритм с указателем на него
		if (node->right)
		{
			return insertNode(node->right, key);
		}

		// Потомка справа нет - создаем новый узел и вставляем в качестве потомка справа
		node->right = buildNode(key);
		return 1;
	}
}

/**
*	Удаление узла бинарного дерева
*
*	@param node Удаляемый узел бинарного дерева
*/
void destroyNode(BinaryTreeNode *node)
{
	if (node)
	{
		free(node);
	}
	return;
}

/**
*	@fn Поиск элемента в бинарном поддереве
*
*	@param node Проверяемый узел бинарного поддерева
*	@param key Искомый элемент
*	@return Указатель на узел поддерева
*/
BinaryTreeNode* nodeSearch(BinaryTreeNode *node, int key)
{
	// Поддерево пусто
	if (!node)
	{
		return NULL;
	}

	// Искомый элемент найден в проверяемом узле
	if (node->key == key)
	{
		return node;
	}
	// Искомый элемент меньше значения в проверяемом узле
	else if (key < node->key)
	{
		return nodeSearch(node->left, key);
	}
	// Искомый элемент больше значения в проверяемом узле
	else
	{
		return nodeSearch(node->right, key);
	}
}

/**
*	@fn Поиск минимального элемента в бинарном поддереве
*
*	@param node Проверяемый узел бинарного поддерева
*	@return Указатель на узел поддерева с минимальным элементом
*/
BinaryTreeNode* getMinNode(BinaryTreeNode *node)
{
	if (!node)
	{
		return NULL;
	}

	if (node->left)
	{
		return getMinNode(node->left);
	}

	return node;
}

/**
*	@fn Поиск максимального элемента в бинарном поддереве
*
*	@param node Проверяемый узел бинарного поддерева
*	@return Указатель на узел поддерева с максимальным элементом
*/
BinaryTreeNode* getMaxNode(BinaryTreeNode *node)
{
	if (!node)
	{
		return NULL;
	}

	if (node->right)
	{
		return getMaxNode(node->right);
	}

	return node;
}

/**
*	@fn Поиск родителя элемента в бинарном поддереве
*
*	@param root Корень бинарного поддерева
*	@param node Проверяемый узел бинарного поддерева
*	@return Указатель на родителя проверяемого узла
*/
BinaryTreeNode* parentNode(BinaryTreeNode *root, BinaryTreeNode *node)
{
	if (root == node || root->left == node || root->right == node)
	{
		return root;
	}

	if (node->key < root->key)
	{
		return parentNode(root->left, node);
	}
	else
	{
		return parentNode(root->right, node);
	}
}

/**
*	@fn Удаление искомого элемента из бинарного поддерева
*
*	@param node Корень бинарного поддерева
*	@param key Искомый элемент для удаления
*	@return (unsigned) В случае удачного удаления - 1, в случае неудачи - 0 
*/
unsigned removeNode(BinaryTreeNode *node, int key)
{
	// Подерево пусто
	if (!node)
	{
		return 0;
	}

	BinaryTreeNode *deleteNode = nodeSearch(node, key);

	// Поддерево не пусто, но элемент не найден в поддереве
	if (!deleteNode)
	{
		return 0;
	}

	// Элемент найден - ищем его родителя
	BinaryTreeNode *parentDeleteNode = parentNode(node, deleteNode);

	// Если нет обоих потомков - просто удаляем узел и перезаписываем ссылку на него у родителя
	if (!deleteNode->left && !deleteNode->right)
	{
		if (parentDeleteNode->left == deleteNode)
		{
			parentDeleteNode->left = NULL;
		}

		if (parentDeleteNode->right == deleteNode)
		{
			parentDeleteNode->right = NULL;
		}

		destroyNode(deleteNode);
	}
	// Если есть левый потомок и нет правого - ссылку на левого потомка запишем родителю
	else if (deleteNode->left && !deleteNode->right)
	{
		if (parentDeleteNode->left == deleteNode)
		{
			parentDeleteNode->left = deleteNode->left;
		}

		if (parentDeleteNode->right == deleteNode)
		{
			parentDeleteNode->right = deleteNode->left;
		}

		destroyNode(deleteNode);
	}
	// Если есть правый потомок и нет левого - ссылку на правого потомка запишем родителю
	else if (!deleteNode->left && deleteNode->right)
	{
		if (parentDeleteNode->left == deleteNode)
		{
			parentDeleteNode->left = deleteNode->right;
		}

		if (parentDeleteNode->right == deleteNode)
		{
			parentDeleteNode->right = deleteNode->right;
		}

		destroyNode(deleteNode);
	}
	// Если есть оба потомка
	else
	{
		// Находим максимальный элемент в левом поддереве и минимальный в правом
		BinaryTreeNode *leftMaxNode = getMaxNode(deleteNode->left), *rightMinNode = getMinNode(deleteNode->right);

		// Если разница между удаляемым элементом и левым максимумом меньше либо равна 
		//		разнице между удаляемым элементом и правым минимумом
		if ((deleteNode->key - leftMaxNode->key) <= (rightMinNode->key - deleteNode->key))
		{
			int tempkey = leftMaxNode->key;
			removeNode(deleteNode->left, leftMaxNode->key);
			deleteNode->key = tempkey;
		}
		else
		{
			int tempkey = rightMinNode->key;
			removeNode(deleteNode->right, rightMinNode->key);
			deleteNode->key = tempkey;
		}
	}
	return 1;
}

/**
*	Печать элемента (узла) бинарного дерева
*
*	@param node Узел бинарного дерева
*/
void printNode(BinaryTreeNode *node)
{
	if (node)
	{
		printf("%4d", node->key);
	}
	return;
}

/**
*	@fn Обход бинарного поддерева (начиная с какого-то узла)
*	с выполнением действия над элементами (через указатель на функцию)
*
*	@param node Корень бинарного поддерева
*	@param direction Направление обхода (@see Direction)
*	@param func Указатель на функцию (действие, совершаемое с узлом дерева)
*/
void bypassBT(BinaryTreeNode *node, Direction dir, void(*func)(BinaryTreeNode*))
{
	switch (dir)
	{
		case RightCenterLeft:
			if (node->right)
			{
				bypassBT(node->right, dir, func);
			}
			func(node);
			if (node->left)
			{
				bypassBT(node->left, dir, func);
			}
			break;
		case LeftRightCenter:
			if (node->left)
			{
				bypassBT(node->left, dir, func);
			}
			if (node->right)
			{
				bypassBT(node->right, dir, func);
			}
			func(node);
			break;
		case RightLeftCenter:
			if (node->right)
			{
				bypassBT(node->right, dir, func);
			}
			if (node->left)
			{
				bypassBT(node->left, dir, func);
			}
			func(node);
			break;
		case CenterLeftRight:
			func(node);
			if (node->left)
			{
				bypassBT(node->left, dir, func);
			}
			if (node->right)
			{
				bypassBT(node->right, dir, func);
			}
			break;
		case CenterRightLeft:
			func(node);
			if (node->right)
			{
				bypassBT(node->right, dir, func);
			}
			if (node->left)
			{
				bypassBT(node->left, dir, func);
			}
			break;
		default:
			if (node->left)
			{
				bypassBT(node->left, dir, func);
			}
			func(node);
			if (node->right)
			{
				bypassBT(node->right, dir, func);
			}
	}
	return;
}

/**
*	@fn Инициализация бинарного дерева
*
*	@param bt Указатель на базу бинарного дерева
*/
void binaryTreeInit(BinaryTree *bt)
{
	bt->root = NULL;
	bt->nodeNum = 0;
	return;
}

/**
*	@fn Вставка элемента в бинарное дерево
*
*	@param bt Указатель на базу бинарного дерева
*	@param key Вставляемый элемент
*/
void insertInBT(BinaryTree *bt, int key)
{
	unsigned insertKey = 0;
	// Дерево пустое - генерируемый элемент станет корневым в дереве
	if (!bt->root)
	{
		bt->root = buildNode(key);
		insertKey = 1;
	}
	else
	{
		// Дерево не пустое - запускаем алгоритм вставки
		insertKey = insertNode(bt->root, key);
	}

	// Увеличиваем количество элементов в дереве на 1 при удачной вставке
	if (insertKey == 1)
	{
		bt->nodeNum++;
	}
	return;
}

/**
*	@fn Поиск минимального элемента в бинарном дереве
*
*	@param bt Указатель на базу бинарного дерева
*	@return Указатель на узел дерева с минимальным элементом
*/
BinaryTreeNode* getMinBTNode(BinaryTree *bt)
{
	return getMinNode(bt->root);
}

/**
*	@fn Поиск максимального элемента в бинарном дереве
*
*	@param bt Указатель на базу бинарного дерева
*	@return Указатель на узел дерева с максимальным элементом
*/
BinaryTreeNode* getMaxBTNode(BinaryTree *bt)
{
	return getMaxNode(bt->root);
}

/**
*	@fn Удаление искомого элемента из бинарного дерева
*
*	@param bt Указатель на базу бинарного дерева
*	@param key Искомый элемент для удаления
*/
void removeFromBT(BinaryTree *bt, int key)
{
	unsigned removeKey = removeNode(bt->root, key);
	if (removeKey == 1)
	{
		bt->nodeNum--;
	}
	return;
}

/**
*	@fn Рекурсивное удаление бинарного дерева
*
*	@param bt Указатель на базу бинарного дерева
*/
void deleteTree(BinaryTree *bt)
{
	bypassBT(bt->root, LeftRightCenter, destroyNode);
	bt->root = NULL;
	bt->nodeNum = 0;
	printf("Tree is empty!\n\n");
	return;
}

/**
*	@fn Рекурсивная печать бинарного дерева в прямом порядке
*
*	@param bt Указатель на базу бинарного дерева
*/
void printTree(BinaryTree *bt)
{
	printf("Tree (%d elements): ", bt->nodeNum);
	bypassBT(bt->root, LeftCenterRight, printNode);
	printf("\n\n");
	return;
}

/**
*	@fn Рекурсивная печать бинарного дерева в обратном порядке
*
*	@param bt Указатель на базу бинарного дерева
*/
void printReverseTree(BinaryTree *bt)
{
	printf("Reversed tree (%d elements): ", bt->nodeNum);
	bypassBT(bt->root, RightCenterLeft, printNode);
	printf("\n\n");
}
