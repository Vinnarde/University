#pragma once
#include <iostream>

class BTreeNode;

class BTree
{
	BTreeNode* root;	// корень дерева
	size_t t;			// минимальна€ степень

public:
	BTree(size_t _t) : root(nullptr), t(_t)
	{
	}

	void traverse() const
	{
		if (root)
			root->traverse(0);
	}

	const BTreeNode* search(const int key) const
	{
		return (root == nullptr) ? nullptr : root->search(key);
	}

	void insert(int key);

	void remove(int key);
};

inline void BTree::insert(const int key)
{
	// дерево пустое
	if (root == nullptr)
	{
		root = new BTreeNode(t, true);
		root->keys[0u] = key;
		root->n = 1;
	}
	else // дерево не пустое
	{
		// если корень заполнен, то его высота увеличиваетс€
		if (root->n == 2u * t - 1u)
		{
			// 1. ¬ыделение пам€ти дл€ нового корн€
			auto* s = new BTreeNode(t, false);

			// 2. сделать старый корень сыном нового
			s->child[0] = root;

			// 3. разбить старый корень и переместить 1 ключ к новому корню
			s->splitChild(0u, root);

			// 4. ” нового корн€ теперь два сына.
			// ќпредел€ем у какого сына будет новый ключ.
			auto i = 0u;
			if (s->keys[0] < key)
				++i;

			s->child[i]->insertNonFull(key);

			// 5. ћен€ем корень
			root = s;
		}
		else // если не заполнен, то просто добавл€ем ключ
			root->insertNonFull(key);
	}
}

inline void BTree::remove(int key)
{
	if (!root)
	{
		std::cout << "The tree is empty\n";
		return;
	}

	// Call the remove function for root
	root->remove(key);

	// If the root node has 0 keys, make its first child as the new root
	//  if it has a child, otherwise set root as nullptr
	if (root->n == 0)
	{
		auto* const tmp = root;
		if (root->leaf)
			root = nullptr;
		else
			root = root->child[0];

		// Free the old root
		delete tmp;
	}
}
