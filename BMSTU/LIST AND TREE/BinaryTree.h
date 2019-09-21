#pragma once
#include "stdafx.h"
#include <iostream>

/**
*	@enum �������� ����������� ������ ��������� ������
*/
enum Direction
{
	LeftCenterRight, ///< ���� - ����� - �����
	RightCenterLeft, ///< ����� - ����� - ����
	LeftRightCenter, ///< ���� - ����� - �����
	RightLeftCenter, ///< ����� - ���� - �����
	CenterLeftRight, ///< ����� - ���� - �����
	CenterRightLeft ///< ����� - ����� - ����
};

/**
*	@struct ���� ��������� ������
*/
template <typename T>
struct BinaryTreeNode
{
	BinaryTreeNode *left; /// @property ��������� �� ������ �������
	BinaryTreeNode *right; /// @property ��������� �� ������� �������
	T key; /// @property ��������, ���������� � ����
};

/**
*	@class ������� ����� ��������� ������
*/
template <typename T>
class BinaryTree
{
private:
	BinaryTreeNode<T> *root; /// @property �������� ���� ��������� ������
	unsigned nodeNum; /// @property ���������� ��������� � �������� ������

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
*	@fn �������� ���� ��������� ������
*
*	@param key ��������, ���������� � ���� ��������� ������
*	@return newNode ��������� �� ����� ���� ��������� ������
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
*	@fn ������� �������� � �������� ���������
*
*	@param node ����������� ���� ��������� ���������
*	@param key ����������� �������
*	@return (unsigned) � ������ ������� ������� �������� - 1, � ������ ������� - 0
*/
template <typename T>
unsigned BinaryTree<T>::insertNode(BinaryTreeNode<T> *node, T key)
{
	// ����������� ���� �� ���������� (������: ������ ������)
	if (!node)
	{
		return 0;
	}

	// �������� �������� ��������� �� ��������� � ����������� ����
	if (node->key == key)
	{
		return 0;
	}
	// �������� �������� ������ ����, ��� ����� � ����������� ����
	else if (key < node->key)
	{
		// ������� ����� ���������� - ������������� �������� � ���������� �� ����
		if (node->left)
		{
			return insertNode(node->left, key);
		}

		// ������� ����� ��� - ������� ����� ���� � ��������� � �������� ������� �����
		node->left = buildNode(key);
		return 1;
	}
	// �������� �������� ������ ����, ��� ����� � ����������� ����
	else
	{
		// ������� ������ ���������� - ������������� �������� � ���������� �� ����
		if (node->right)
		{
			return insertNode(node->right, key);
		}

		// ������� ������ ��� - ������� ����� ���� � ��������� � �������� ������� ������
		node->right = buildNode(key);
		return 1;
	}
}

/**
*	�������� ���� ��������� ������
*
*	@param node ��������� ���� ��������� ������
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
*	@fn ����� �������� � �������� ���������
*
*	@param node ����������� ���� ��������� ���������
*	@param key ������� �������
*	@return ��������� �� ���� ���������
*/
template <typename T>
BinaryTreeNode<T>* BinaryTree<T>::nodeSearch(BinaryTreeNode<T> *node, T key)
{
	// ��������� �����
	if (!node)
	{
		return nullptr;
	}

	// ������� ������� ������ � ����������� ����
	if (node->key == key)
	{
		return node;
	}
	// ������� ������� ������ �������� � ����������� ����
	else if (key < node->key)
	{
		return nodeSearch(node->left, key);
	}
	// ������� ������� ������ �������� � ����������� ����
	else
	{
		return nodeSearch(node->right, key);
	}
}

/**
*	@fn ����� ������������ �������� � �������� ���������
*
*	@param node ����������� ���� ��������� ���������
*	@return ��������� �� ���� ��������� � ����������� ���������
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
*	@fn ����� ������������� �������� � �������� ���������
*
*	@param node ����������� ���� ��������� ���������
*	@return ��������� �� ���� ��������� � ������������ ���������
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
*	@fn ����� �������� �������� � �������� ���������
*
*	@param root ������ ��������� ���������
*	@param node ����������� ���� ��������� ���������
*	@return ��������� �� �������� ������������ ����
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
*	@fn �������� �������� �������� �� ��������� ���������
*
*	@param node ������ ��������� ���������
*	@param key ������� ������� ��� ��������
*	@return (unsigned) � ������ �������� �������� - 1, � ������ ������� - 0 
*/
template <typename T>
unsigned BinaryTree<T>::removeNode(BinaryTreeNode<T> *node, T key)
{
	// �������� �����
	if (!node)
	{
		return 0;
	}

	BinaryTreeNode *deleteNode = nodeSearch(node, key);

	// ��������� �� �����, �� ������� �� ������ � ���������
	if (!deleteNode)
	{
		return 0;
	}

	// ������� ������ - ���� ��� ��������
	BinaryTreeNode *parentDeleteNode = parentNode(node, deleteNode);

	// ���� ��� ����� �������� - ������ ������� ���� � �������������� ������ �� ���� � ��������
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
	// ���� ���� ����� ������� � ��� ������� - ������ �� ������ ������� ������� ��������
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
	// ���� ���� ������ ������� � ��� ������ - ������ �� ������� ������� ������� ��������
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
	// ���� ���� ��� �������
	else
	{
		// ������� ������������ ������� � ����� ��������� � ����������� � ������
		BinaryTreeNode *leftMaxNode = getMaxNode(deleteNode->left), *rightMinNode = getMinNode(deleteNode->right);

		// ���� ������� ����� ��������� ��������� � ����� ���������� ������ ���� ����� 
		//		������� ����� ��������� ��������� � ������ ���������
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
*	������ �������� (����) ��������� ������
*
*	@param node ���� ��������� ������
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
*	@fn ����� ��������� ��������� (������� � ������-�� ����)
*	� ����������� �������� ��� ���������� (����� ��������� �� �������)
*
*	@param node ������ ��������� ���������
*	@param direction ����������� ������ (@see Direction)
*	@param func ��������� �� ������� (��������, ����������� � ����� ������)
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
*	@fn ������� �������� � �������� ������
*
*	@param bt ��������� �� ���� ��������� ������
*	@param key ����������� �������
*/
template <typename T>
void BinaryTree<T>::insertInBT(BinaryTree<T> *bt, T key)
{
	unsigned insertKey = 0;
	// ������ ������ - ������������ ������� ������ �������� � ������
	if(!bt->root)
	{
		bt->root = buildNode(key);
		insertKey = 1;
	}
	else
	{
		// ������ �� ������ - ��������� �������� �������
		insertKey = insertNode(bt->root, key);
	}

	// ����������� ���������� ��������� � ������ �� 1 ��� ������� �������
	if (insertKey == 1)
	{
		bt->nodeNum++;
	}
	return;
}

/**
*	@fn �������� �������� �������� �� ��������� ������
*
*	@param bt ��������� �� ���� ��������� ������
*	@param key ������� ������� ��� ��������
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
*	@fn ����������� �������� ��������� ������
*
*	@param bt ��������� �� ���� ��������� ������
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
*	@fn ����������� ������ ��������� ������ � ������ �������
*
*	@param bt ��������� �� ���� ��������� ������
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
*	@fn ����������� ������ ��������� ������ � �������� �������
*
*	@param bt ��������� �� ���� ��������� ������
*/
template <typename T>
void BinaryTree<T>::printReverseTree(BinaryTree<T> *bt)
{
	std::cout << "Reversed tree (" << bt->nodeNum << " elements): ";
	bypassBT(bt->root, RightCenterLeft, printNode);
	std::cout << std::endl;
}
