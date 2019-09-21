#pragma once
#include <iostream>

enum Direction
{
	LeftCenterRight, 
	RightCenterLeft, 
	LeftRightCenter, 
	RightLeftCenter, 
	CenterLeftRight, 
	CenterRightLeft 
};

template <typename TKey>
class BinaryTree
{
	private:
		typedef struct BTNode 
		{
			BTNode *left; 
			BTNode *right; 
			TKey key; 
		} BTNode;

		// Объяснение по поводу typename и сложных типов данных
		//https://ru.stackoverflow.com/questions/167210/error-c2143-syntax-error-missing-before

		//https://msdn.microsoft.com/ru-ru/library/0afb82ta.aspx

		BTNode* buildNode(TKey key);
		void destroyNode(BTNode *node);
		BTNode* nodeSearch(TKey key) const;
		BTNode* getMaxNode(BTNode *node) const;
		BTNode* getMinNode(BTNode *node) const;
		BTNode* parentNode(BTNode *root, BTNode *node) const;
		void printNode(BTNode *node) const;
		void bypass(BTNode *node, Direction dir, void(*func)(BTNode *));
		std::ostream& print(BTNode *node, Direction dir, std::ostream &os) const; 

		BTNode *root;
		unsigned nodeNum;

	public:
		BinaryTree() : root(nullptr), nodeNum(0) {}
		BinaryTree(TKey k) : nodeNum(1) { root = buildNode(k); }
		~BinaryTree() { clear(); };

		void insert(TKey key);
		void remove(TKey key);
		bool find(TKey key) const { return (bool)nodeSearch(key); }
		TKey minKey() const;
		TKey maxKey() const;
		void clear();
		void reversePrint();
		bool isEmpty() const { return (bool)nodeNum; }
		
		template <typename TKey>
		friend std::ostream& operator<<(std::ostream& os, const BinaryTree &bt);
};

// вспомогательные private-методы

template <typename TKey> typename
BinaryTree<TKey>::BTNode* BinaryTree<TKey>::buildNode(TKey key)
{
	BTNode *newNode = new BTNode;
	newNode->key = key;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}

template <typename TKey>
void BinaryTree<TKey>::destroyNode(BTNode *node)
{
	if (node)
	{
		delete(node);
	}
	return;
}

template <typename TKey> typename
BinaryTree<TKey>::BTNode* BinaryTree<TKey>::nodeSearch(TKey key) const
{
	BTNode *searchResult = root;
	
	while (searchResult->key != key && searchResult != nullptr)
	{
		searchResult = (searchResult->key < key) ? searchResult->left : searchResult->right;
	}

	return searchResult;
}

template <typename TKey> typename
BinaryTree<TKey>::BTNode* BinaryTree<TKey>::getMaxNode(BTNode *node) const
{
	if (node)
	{
		if (node->right)
		{
			return getMaxNode(node->right);
		}
		return node;
	}
}

template <typename TKey> typename
BinaryTree<TKey>::BTNode* BinaryTree<TKey>::getMinNode(BTNode *node) const
{
	if (node)
	{
		if (node->left)
		{
			return getMinNode(node->left);
		}
		return node;
	}
}

template <typename TKey> typename
BinaryTree<TKey>::BTNode* BinaryTree<TKey>::parentNode(BTNode *root, BTNode *node) const
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

template <typename TKey>
void BinaryTree<TKey>::printNode(BTNode *node) const
{
	if (node)
	{
		std::cout << node->key << ' ';
	}
	return;
}

template <typename TKey>
void BinaryTree<TKey>::bypass(BTNode *node, Direction dir, void(*func)(BTNode*))
{
	switch (dir)
	{
		case RightCenterLeft:
			if (node->right)
			{
				bypass(node->right, dir, func);
			}
			func(node);
			if (node->left)
			{
				bypass(node->left, dir, func);
			}
			break;
		case LeftRightCenter:
			if (node->left)
			{
				bypass(node->left, dir, func);
			}
			if (node->right)
			{
				bypass(node->right, dir, func);
			}
			func(node);
			break;
		case RightLeftCenter:
			if (node->right)
			{
				bypass(node->right, dir, func);
			}
			if (node->left)
			{
				bypass(node->left, dir, func);
			}
			func(node);
			break;
		case CenterLeftRight:
			func(node);
			if (node->left)
			{
				bypass(node->left, dir, func);
			}
			if (node->right)
			{
				bypass(node->right, dir, func);
			}
			break;
		case CenterRightLeft:
			func(node);
			if (node->right)
			{
				bypass(node->right, dir, func);
			}
			if (node->left)
			{
				bypass(node->left, dir, func);
			}
			break;
		default:
			if (node->left)
			{
				bypass(node->left, dir, func);
			}
			func(node);
			if (node->right)
			{
				bypass(node->right, dir, func);
			}
	}
	return;
}

template<typename TKey>
inline std::ostream& BinaryTree<TKey>::print(BTNode *node, Direction dir, std::ostream &os) const
{
	switch (dir)
	{
		case RightCenterLeft:
			if (node->right)
			{
				print(node->right, dir, os);
			}
			os << node->value << ' ';
			if (node->left)
			{
				print(node->left, dir, os);
			}
			break;
		case LeftRightCenter:
			if (node->left)
			{
				print(node->left, dir, os);
			}
			if (node->right)
			{
				print(node->right, dir, os);
			}
			os << node->value << ' ';
			break;
		case RightLeftCenter:
			if (node->right)
			{
				print(node->right, dir, os);
			}
			if (node->left)
			{
				print(node->left, dir, os);
			}
			os << node->value << ' ';
			break;
		case CenterLeftRight:
			os << node->value << ' ';
			if (node->left)
			{
				print(node->left, dir, os);
			}
			if (node->right)
			{
				print(node->right, dir, os);
			}
			break;
		case CenterRightLeft:
			os << node->value << ' ';
			if (node->right)
			{
				print(node->right, dir, os);
			}
			if (node->left)
			{
				print(node->left, dir, os);
			}
			break;
		default:
			if (node->left)
			{
				print(node->left, dir, os);
			}
			os << node->value << ' ';
			if (node->right)
			{
				print(node->right, dir, os);
			}
	}
	return os;
}

// основные (публичные) методы бинарного дерева

template <typename TKey>
void BinaryTree<TKey>::insert(TKey key)
{
	unsigned insertKey = 0;
	
	if (!root)
	{
		root = buildNode(key);
		insertKey = 1;
	}
	else
	{
		BTNode *node = root;

		while (true)
		{
			if (node->key == key)
			{
				break;
			}
			
			if (key < node->key)
			{
				if (node->left)
				{
					node = node->left;
					continue;
				}

				node->left = buildNode(key);
				insertKey = 1;
				break;
			}
			else
			{
				if (node->right)
				{
					node = node->right;
					continue;
				}

				node->right = buildNode(key);
				insertKey = 1;
				break;
			}
		}
	}

	// Увеличиваем количество элементов в дереве на 1 при удачной вставке
	if (insertKey == 1)
	{
		nodeNum++;
	}
}

template <typename TKey>
void BinaryTree<TKey>::remove(TKey key)
{
	// Подерево пусто
	if (!root)
	{
		return;
	}

	BTNode *deleteNode = nodeSearch(key);

	// Поддерево не пусто, но элемент не найден в поддереве
	if (!deleteNode)
	{
		return;
	}

	// Элемент найден - ищем его родителя
	BTNode *parentDeleteNode = parentNode(root, deleteNode);

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
		BTNode *leftMaxNode = getMaxNode(deleteNode->left), *rightMinNode = getMinNode(deleteNode->right);

		// Если разница между удаляемым элементом и левым максимумом меньше либо равна 
		//		разнице между удаляемым элементом и правым минимумом
		if ((deleteNode->key - leftMaxNode->key) <= (rightMinNode->key - deleteNode->key))
		{
			int tempkey = leftMaxNode->key;
			remove(leftMaxNode->key);
			deleteNode->key = tempkey;
		}
		else
		{
			int tempkey = rightMinNode->key;
			remove(rightMinNode->key);
			deleteNode->key = tempkey;
		}
	}

	--nodeNum;
}

template <typename TKey>
TKey BinaryTree<TKey>::minKey() const
{
	if (!root)
	{
		return (TKey)0;
	}

	BTNode *min = root;
	while (min->left)
	{
		min = min->left;
	}

	return min->key;
}

template <typename TKey>
TKey BinaryTree<TKey>::maxKey() const
{
	if (!root)
	{
		return (TKey)0;
	}

	BTNode *max = root;
	while (max->right)
	{
		max = max->right;
	}

	return max->key;
}

template <typename TKey>
void BinaryTree<TKey>::clear()
{
	bypass(root, LeftRightCenter, destroyNode);
	root = nullptr;
	nodeNum = 0;
	std::cout << "Tree is empty!" << std::endl;
	return;
}

template <typename TKey>
void BinaryTree<TKey>::reversePrint()
{
	std::cout << "Reversed tree (" << nodeNum << " elements): ";
	bypass(root, RightCenterLeft, &printNode);
	std::cout << std::endl;
}

template<typename TKey>
inline std::ostream& operator<<(std::ostream &os, const BinaryTree<TKey> &bt)
{
	if (bt.isEmpty())
	{
		os << "Tree is empty!" << std::endl;
		return os;
	}

	bt.print(bt.root, LeftCenterRight, os);
	std::cout << std::endl;
	return os;
}
