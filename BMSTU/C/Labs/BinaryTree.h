#include <stdio.h>
#include <stdlib.h>

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
typedef struct BinaryTreeNode
{
	BinaryTreeNode *left; /// @property ��������� �� ������ �������
	BinaryTreeNode *right; /// @property ��������� �� ������� �������
	int key; /// @property ��������, ���������� � ����
} BinaryTreeNode;

/**
*	@struct ������� ��������� ��������� ������
*/
typedef struct
{
	BinaryTreeNode *root; /// @property �������� ���� ��������� ������
	unsigned nodeNum; /// @property ���������� ��������� � �������� ������
} BinaryTree;

/**
*	@fn �������� ���� ��������� ������
*
*	@param key ��������, ���������� � ���� ��������� ������
*	@return newNode ��������� �� ����� ���� ��������� ������
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
*	@fn ������� �������� � �������� ���������
*
*	@param node ����������� ���� ��������� ���������
*	@param key ����������� �������
*	@return (unsigned) � ������ ������� ������� �������� - 1, � ������ ������� - 0
*/
unsigned insertNode(BinaryTreeNode *node, int key)
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
void destroyNode(BinaryTreeNode *node)
{
	if (node)
	{
		free(node);
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
BinaryTreeNode* nodeSearch(BinaryTreeNode *node, int key)
{
	// ��������� �����
	if (!node)
	{
		return NULL;
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
*	@fn ����� ������������� �������� � �������� ���������
*
*	@param node ����������� ���� ��������� ���������
*	@return ��������� �� ���� ��������� � ������������ ���������
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
*	@fn ����� �������� �������� � �������� ���������
*
*	@param root ������ ��������� ���������
*	@param node ����������� ���� ��������� ���������
*	@return ��������� �� �������� ������������ ����
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
*	@fn �������� �������� �������� �� ��������� ���������
*
*	@param node ������ ��������� ���������
*	@param key ������� ������� ��� ��������
*	@return (unsigned) � ������ �������� �������� - 1, � ������ ������� - 0 
*/
unsigned removeNode(BinaryTreeNode *node, int key)
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
			parentDeleteNode->left = NULL;
		}

		if (parentDeleteNode->right == deleteNode)
		{
			parentDeleteNode->right = NULL;
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
void printNode(BinaryTreeNode *node)
{
	if (node)
	{
		printf("%4d", node->key);
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
*	@fn ������������� ��������� ������
*
*	@param bt ��������� �� ���� ��������� ������
*/
void binaryTreeInit(BinaryTree *bt)
{
	bt->root = NULL;
	bt->nodeNum = 0;
	return;
}

/**
*	@fn ������� �������� � �������� ������
*
*	@param bt ��������� �� ���� ��������� ������
*	@param key ����������� �������
*/
void insertInBT(BinaryTree *bt, int key)
{
	unsigned insertKey = 0;
	// ������ ������ - ������������ ������� ������ �������� � ������
	if (!bt->root)
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
*	@fn ����� ������������ �������� � �������� ������
*
*	@param bt ��������� �� ���� ��������� ������
*	@return ��������� �� ���� ������ � ����������� ���������
*/
BinaryTreeNode* getMinBTNode(BinaryTree *bt)
{
	return getMinNode(bt->root);
}

/**
*	@fn ����� ������������� �������� � �������� ������
*
*	@param bt ��������� �� ���� ��������� ������
*	@return ��������� �� ���� ������ � ������������ ���������
*/
BinaryTreeNode* getMaxBTNode(BinaryTree *bt)
{
	return getMaxNode(bt->root);
}

/**
*	@fn �������� �������� �������� �� ��������� ������
*
*	@param bt ��������� �� ���� ��������� ������
*	@param key ������� ������� ��� ��������
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
*	@fn ����������� �������� ��������� ������
*
*	@param bt ��������� �� ���� ��������� ������
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
*	@fn ����������� ������ ��������� ������ � ������ �������
*
*	@param bt ��������� �� ���� ��������� ������
*/
void printTree(BinaryTree *bt)
{
	printf("Tree (%d elements): ", bt->nodeNum);
	bypassBT(bt->root, LeftCenterRight, printNode);
	printf("\n\n");
	return;
}

/**
*	@fn ����������� ������ ��������� ������ � �������� �������
*
*	@param bt ��������� �� ���� ��������� ������
*/
void printReverseTree(BinaryTree *bt)
{
	printf("Reversed tree (%d elements): ", bt->nodeNum);
	bypassBT(bt->root, RightCenterLeft, printNode);
	printf("\n\n");
}
