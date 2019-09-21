#pragma once
#include "stdafx.h"
#include <iostream>

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
template <typename T>
struct BinaryTreeNode
{
	BinaryTreeNode *left; /// @property Указатель на левого потомка
	BinaryTreeNode *right; /// @property Указатель на правого потомка
	T key; /// @property Значение, хранящееся в узле
};

/**
*	@class Базовый класс бинарного дерева
*/
template <typename T>
class BinaryTree
{
private:
	BinaryTreeNode<T> *root; /// @property Корневой узел бинарного дерева
	unsigned nodeNum; /// @property Количество элементов в бинарном дереве

	BinaryTreeNode<T>* buildNode(T key);
	unsigned insertNode(BinaryTreeNode<T> *node, T key);
	void destroyNode(BinaryTreeNode<T> *node);
	BinaryTreeNode<T>* nodeSearch(BinaryTreeNode<T> *node, T key);
	BinaryTreeNode<T>* getMinNode(BinaryTreeNode<T> *node);
	BinaryTreeNode<T>* getMaxNode(BinaryTreeNode<T> *node);
	BinaryTreeNode<T>* parentNode(BinaryTreeNode<T> *root, BinaryTreeNode<T> *node);
	unsigned removeNode(BinaryTreeNode<T> *node, T key);
	void printNode(BinaryTreeNode<T> *node);
	void bypassBT(BinaryTreeNode<T> *node, Direction dir, void(*func)(BinaryTreeNode<T>*));
	void insertInBT(BinaryTree<T> *bt, T key);
	void removeFromBT(BinaryTree<T> *bt, T key);
	void deleteTree(BinaryTree<T> *bt);
	void printTree(BinaryTree<T> *bt);
	void printReverseTree(BinaryTree<T> *bt);

public:
	BinaryTree(unsigned num = 0) : root(nullptr), nodeNum(num)	{}
	~BinaryTree()	{deleteBT();}

	void insertIn(T key)	{insertInBT(this, key);}
	BinaryTreeNode<T>* search(T key)	{return nodeSearch(root, key);}
	BinaryTreeNode<T>* getMinBTNode()	{return getMinNode(root);}
	BinaryTreeNode<T>* getMaxBTNode()	{return getMaxNode(root);}
	void removeFromBT(T key)	{removeFromBT(this, key);}
	void deleteBT()	{deleteTree(this);}
	void printBT()	{printTree(this);}
	void printReverseBT()	{printReverseTree(this);}
};

/**
*	@fn Создание узла бинарного дерева
*
*	@param key Значение, помещаемое в узел бинарного дерева
*	@return newNode Указатель на новый узел бинарного дерева
*/
template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::buildNode(T key)
{
	BinaryTreeNode *newNode = new BinaryTreeNode;
	newNode->key = key;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

/**
*	@fn Вставка элемента в бинарное поддерево
*
*	@param node Проверяемый узел бинарного поддерева
*	@param key Вставляемый элемент
*	@return (unsigned) В случае удачной вставки элемента - 1, в случае неудачи - 0
*/
template <typename T>
unsigned BinaryTree<T>::insertNode(BinaryTreeNode<T> *node, T key)
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
template <typename T>
void BinaryTree<T>::destroyNode(BinaryTreeNode<T> *node)
{
	if (node)
	{
		delete node;
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
template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::nodeSearch(BinaryTreeNode<T> *node, T key)
{
	// Поддерево пусто
	if (!node)
	{
		return nullptr;
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
template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::getMinNode(BinaryTreeNode<T> *node)
{
	if (!node)
	{
		return nullptr;
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
template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::getMaxNode(BinaryTreeNode<T> *node)
{
	if (!node)
	{
		return nullptr;
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
template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::parentNode(BinaryTreeNode<T> *root, BinaryTreeNode<T> *node)
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
template <typename T>
unsigned BinaryTree<T>::removeNode(BinaryTreeNode<T> *node, T key)
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
			parentDeleteNode->left = nullptr;
		}

		if (parentDeleteNode->right == deleteNode)
		{
			parentDeleteNode->right = nullptr;
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
template <typename T>
void BinaryTree<T>::printNode(BinaryTreeNode<T> *node)
{
	if (node)
	{
		std::cout << node->key;
		//printf("%4d", node->key);
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
template <typename T>
void BinaryTree<T>::bypassBT(BinaryTreeNode<T> *node, Direction dir, void(*func)(BinaryTreeNode<T>*))
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
*	@fn Вставка элемента в бинарное дерево
*
*	@param bt Указатель на базу бинарного дерева
*	@param key Вставляемый элемент
*/
template <typename T>
void BinaryTree<T>::insertInBT(BinaryTree<T> *bt, T key)
{
	unsigned insertKey = 0;
	// Дерево пустое - генерируемый элемент станет корневым в дереве
	if(!bt->root)
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
*	@fn Удаление искомого элемента из бинарного дерева
*
*	@param bt Указатель на базу бинарного дерева
*	@param key Искомый элемент для удаления
*/
template <typename T>
void BinaryTree<T>::removeFromBT(BinaryTree<T> *bt, T key)
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
template <typename T>
void BinaryTree<T>::deleteTree(BinaryTree<T> *bt)
{
	bypassBT(bt->root, LeftRightCenter, destroyNode);
	bt->root = nullptr;
	bt->nodeNum = 0;
	std::cout << "Tree is empty!" << std::endl;
	return;
}

/**
*	@fn Рекурсивная печать бинарного дерева в прямом порядке
*
*	@param bt Указатель на базу бинарного дерева
*/
template <typename T>
void BinaryTree<T>::printTree(BinaryTree<T> *bt)
{
	std::cout << "Tree (" << bt->nodeNum << " elements): ";
	bypassBT(bt->root, LeftCenterRight, printNode);
	std::cout << std::endl;
	return;
}

/**
*	@fn Рекурсивная печать бинарного дерева в обратном порядке
*
*	@param bt Указатель на базу бинарного дерева
*/
template <typename T>
void BinaryTree<T>::printReverseTree(BinaryTree<T> *bt)
{
	std::cout << "Reversed tree (" << bt->nodeNum << " elements): ";
	bypassBT(bt->root, RightCenterLeft, printNode);
	std::cout << std::endl;
}
