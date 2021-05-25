#pragma once
#include <iostream>
#include <string>
using std::size_t;

class BTreeNode
{
	int* keys;			// массив клчюей
	size_t t;			// минимальная степень t
	BTreeNode** child;	// массив указателей на детей
	size_t n;			// текущее кол-во ключей
	bool leaf;			// true - когда узел листовой, иначе - false

public:
	BTreeNode(size_t _t, bool _leaf);

	void insertNonFull(int key);

	void splitChild(int idx, BTreeNode* y);

	void traverse(int tab) const;

	const BTreeNode* search(int key) const;

	// A function that returns the index of the first key that is greater
	// or equal to k
	int findKey(int key) const;

	// A wrapper function to remove the key k in subtree rooted with
	// this node.
	void remove(int key);
	// A function to remove the key present in idx-th position in
	// this node which is a leaf
	void removeFromLeaf(int idx);

	// A function to remove the key present in idx-th position in
	// this node which is a non-leaf node
	void removeFromNonLeaf(int idx);

	// A function to get the predecessor of the key- where the key
	// is present in the idx-th position in the node
	int getPred(int idx) const;

	// A function to get the successor of the key- where the key
	// is present in the idx-th position in the node
	int getSucc(int idx) const;

	// A function to fill up the child node present in the idx-th
	// position in the child[] array if that child has less than t-1 keys
	void fill(int idx);

	// A function to borrow a key from the child[idx-1]-th node and place
	// it in child[idx]th node
	void borrowFromPrev(int idx) const;

	// A function to borrow a key from the child[idx+1]-th node and place it
	// in child[idx]th node
	void borrowFromNext(int idx) const;

	// A function to merge idx-th child of the node with (idx+1)th child of
	// the node
	void merge(int idx);

	friend class BTree;
};

inline BTreeNode::BTreeNode(size_t _t, bool _leaf)
{
	t = _t;
	leaf = _leaf;

	keys = new int[2u * t - 1u];
	child = new BTreeNode * [2u * t];

	n = 0u;
}

inline void BTreeNode::insertNonFull(const int key)
{
	// индекс самого правого элемента
	int i = n - 1;

	// если это лист:
	if (leaf)
	{
		// Следующий цикл делает 2 вещи:
		// a. находит место нового ключа, который будет вставлен
		// b. перемещает все большие ключи на одно место вперед
		while (i >= 0 && keys[i] > key)
		{
			keys[i + 1] = keys[i];
			--i;
		}

		keys[i + 1] = key;
		n = n + 1;
	}
	else // если не лист
	{
		// находим сына, у которого будет новый ключ
		while (i >= 0 && keys[i] > key)
			--i;

		// если сын заполнен
		if (child[i + 1]->n == 2 * t - 1)
		{
			// 1. разбиение узла
			splitChild(i + 1, child[i + 1]);

			// 2. After split, middle key of child[i] goes up
			// and child[i] is splitted into two. Find which of
			// twe two is going to have the new key.
			// 2. После разбиения средний ключ уходит вверх
			// и child[i] разбит пополам. Находим место для
			// нового ключа.

			if (keys[i + 1] < key)
				++i;
		}
		child[i + 1]->insertNonFull(key);
	}
}

inline void BTreeNode::splitChild(int idx, BTreeNode* y)
{
	// создаём новый узел, который будет хранить (t-1) ключей y
	BTreeNode* z = new BTreeNode(y->t, y->leaf);
	z->n = t - 1;

	// 1. копируем первые (t-1) ключей y в z
	for (size_t i = 0u; i < t - 1u; ++i)
	{
		z->keys[i] = y->keys[i + t];
	}

	// 2. копируем последние t ключей y в z
	if (!y->leaf)
	{
		for (size_t j = 0u; j < t; ++j)
		{
			z->child[j] = y->child[j + t];
		}
	}

	// 3. уменьшаем кол-во ключей в y
	y->n = t - 1;

	// 4. создаём место для новый потомков
	for (size_t j = n; j >= idx + 1; --j)
	{
		child[j + 1u] = child[j];
	}

	// 5. связываем новый дочерний узел с узлом z
	child[idx + 1u] = z;

	// Ключ y переместится в этот узел. Находим место
	// нового ключа и перемещаем все большие ключи на одно место вперед
	for (int j = n - 1; j >= idx; j--)
		keys[j + 1] = keys[j];

	// копируем средний ключ y в этот узел
	keys[idx] = y->keys[t - 1];

	// увеличиваем количество ключей в этом узле
	n = n + 1;
}

inline void BTreeNode::traverse(int tab) const
{
	int i;
	std::string str;

	for (int j = 0; j < tab; ++j)
		str += '\t';

	for (i = 0u; i < n; ++i)
	{
		if (!leaf)
			child[i]->traverse(tab + 1);

		std::cout << str << keys[i] << '\n';
	}

	if (!leaf)
		child[i]->traverse(tab + 1);
}

inline const BTreeNode* BTreeNode::search(const int key) const
{
	auto i = 0u;

	while (i < n && key > keys[i])
		++i;

	if (keys[i] == key)
		return this;

	if (leaf)
		return nullptr;

	return child[i]->search(key);
}

inline int BTreeNode::findKey(int key) const
{
	int idx = 0;
	while (idx < n && keys[idx] < key)
		++idx;

	return idx;
}

inline void BTreeNode::remove(int key)
{
	auto idx = findKey(key);

	// the key to be removed is present in this node
	if (idx < n && keys[idx] == key)
	{
		if (leaf)
			removeFromLeaf(idx);
		else
			removeFromNonLeaf(idx);
	} // the key to be removed isn't present in this node
	else
	{
		// if this node is a leaf node, then the key isn't present in tree
		if (leaf)
		{
			std::clog << "The key " << key << " doesn't exist in the tree.\n";
			return;
		}

		// The key to be removed is present in the sub-tree rooted with this node
		// The flag indicates whether the key is present in the sub-tree rooted
		// with the last child of this node
		bool flag = (idx == n ? true : false);


		// If the child where the key is supposed to exist has less that t keys,
		// we fill that child
		if (child[idx]->n < t)
			fill(idx);

		// If the last child has been merged, it must have merged with the previous
		// child and so we recurse on the (idx-1)th child. Else, we recurse on the
		// (idx)th child which now has at least t keys
		if (flag && idx > n)
			child[idx - 1]->remove(key);
		else
			child[idx]->remove(key);
	}
}

inline void BTreeNode::removeFromLeaf(int idx)
{
	// move all the keys after idx-th pos one place backward
	for (auto i = idx + 1; i < n; ++i)
	{
		keys[i - 1] = keys[i];
	}

	// reduce the count of keys
	--n;
}

inline void BTreeNode::removeFromNonLeaf(int idx)
{
	auto k = keys[idx];

	int key = keys[idx];

	// If the child that precedes key (child[idx]) has atleast t keys,
	// find the predecessor 'pred' of key in the subtree rooted at
	// child[idx]. Replace key by pred. Recursively delete pred
	// in child[idx]
	if (child[idx]->n >= t)
	{
		int pred = getPred(idx);
		keys[idx] = pred;
		child[idx]->remove(pred);
	}

	// If the child child[idx] has less that t keys, examine child[idx+1].
	// If child[idx+1] has atleast t keys, find the successor 'succ' of key in
	// the subtree rooted at child[idx+1]
	// Replace key by succ
	// Recursively delete succ in child[idx+1]
	else if (child[idx + 1]->n >= t)
	{
		int succ = getSucc(idx);
		keys[idx] = succ;
		child[idx + 1]->remove(succ);
	}

	// If both child[idx] and child[idx+1] has less that t keys,merge key and all of child[idx+1]
	// into child[idx]
	// Now child[idx] contains 2t-1 keys
	// Free child[idx+1] and recursively delete key from child[idx]
	else
	{
		merge(idx);
		child[idx]->remove(key);
	}
}

inline int BTreeNode::getPred(int idx) const
{
	// Keep moving to the right most node until we reach a leaf
	BTreeNode* cur = child[idx];
	while (!cur->leaf)
		cur = cur->child[cur->n];

	// Return the last key of the leaf
	return cur->keys[cur->n - 1];
}

inline int BTreeNode::getSucc(int idx) const
{

	// Keep moving the left most node starting from child[idx+1] until we reach a leaf
	BTreeNode* cur = child[idx + 1];
	while (!cur->leaf)
		cur = cur->child[0];

	// Return the first key of the leaf
	return cur->keys[0];
}

inline void BTreeNode::fill(int idx)
{

	// If the previous child(child[idx-1]) has more than t-1 keys, borrow a key
	// from that child
	if (idx != 0 && child[idx - 1]->n >= t)
		borrowFromPrev(idx);

	// If the next child(child[idx+1]) has more than t-1 keys, borrow a key
	// from that child
	else if (idx != n && child[idx + 1]->n >= t)
		borrowFromNext(idx);

	// Merge child[idx] with its sibling
	// If child[idx] is the last child, merge it with with its previous sibling
	// Otherwise merge it with its next sibling
	else
	{
		if (idx != n)
			merge(idx);
		else
			merge(idx - 1);
	}
}

inline void BTreeNode::borrowFromPrev(int idx) const
{
	BTreeNode* child_node = child[idx];
	BTreeNode* sibling_node = child[idx - 1];

	// The last key from child[idx-1] goes up to the parent and key[idx-1]
	// from parent is inserted as the first key in child[idx]. Thus, the  loses
	// sibling one key and child gains one key

	// Moving all key in child[idx] one step ahead
	for (int i = child_node->n - 1; i >= 0; --i)
		child_node->keys[i + 1] = child_node->keys[i];

	// If child[idx] is not a leaf, move all its child pointers one step ahead
	if (!child_node->leaf)
	{
		for (int i = child_node->n; i >= 0; --i)
			child_node->child[i + 1] = child_node->child[i];
	}

	// Setting child's first key equal to keys[idx-1] from the current node
	child_node->keys[0] = keys[idx - 1];

	// Moving sibling's last child as child[idx]'s first child
	if (!child_node->leaf)
		child_node->child[0] = sibling_node->child[sibling_node->n];

	// Moving the key from the sibling to the parent
	// This reduces the number of keys in the sibling
	keys[idx - 1] = sibling_node->keys[sibling_node->n - 1];

	child_node->n += 1;
	sibling_node->n -= 1;
}

inline void BTreeNode::borrowFromNext(int idx) const
{

	BTreeNode* childe_node = child[idx];
	BTreeNode* sibling_node = child[idx + 1];

	// keys[idx] is inserted as the last key in child[idx]
	childe_node->keys[(childe_node->n)] = keys[idx];

	// Sibling's first child is inserted as the last child
	// into child[idx]
	if (!(childe_node->leaf))
		childe_node->child[(childe_node->n) + 1] = sibling_node->child[0];

	//The first key from sibling is inserted into keys[idx]
	keys[idx] = sibling_node->keys[0];

	// Moving all keys in sibling one step behind
	for (int i = 1; i < sibling_node->n; ++i)
		sibling_node->keys[i - 1] = sibling_node->keys[i];

	// Moving the child pointers one step behind
	if (!sibling_node->leaf)
	{
		for (int i = 1; i <= sibling_node->n; ++i)
			sibling_node->child[i - 1] = sibling_node->child[i];
	}

	// Increasing and decreasing the key count of child[idx] and child[idx+1]
	// respectively
	childe_node->n += 1;
	sibling_node->n -= 1;
}

inline void BTreeNode::merge(int idx)
{
	BTreeNode* child_node = child[idx];
	BTreeNode* sibling_node = child[idx + 1];

	// Pulling a key from the current node and inserting it into (t-1)th
	// position of child[idx]
	child_node->keys[t - 1] = keys[idx];

	// Copying the keys from child[idx+1] to child[idx] at the end
	for (int i = 0; i < sibling_node->n; ++i)
		child_node->keys[i + t] = sibling_node->keys[i];

	// Copying the child pointers from child[idx+1] to child[idx]
	if (!child_node->leaf)
	{
		for (int i = 0; i <= sibling_node->n; ++i)
			child_node->child[i + t] = sibling_node->child[i];
	}

	// Moving all keys after idx in the current node one step before -
	// to fill the gap created by moving keys[idx] to child[idx]
	for (int i = idx + 1; i < n; ++i)
		keys[i - 1] = keys[i];

	// Moving the child pointers after (idx+1) in the current node one
	// step before
	for (int i = idx + 2; i <= n; ++i)
		child[i - 1] = child[i];

	// Updating the key count of child and the current node
	child_node->n += sibling_node->n + 1;
	n--;

	// Freeing the memory occupied by sibling
	delete(sibling_node);
}