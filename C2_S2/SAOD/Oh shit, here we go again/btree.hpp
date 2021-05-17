#pragma once
#include <iostream>

class BTreeNode;

class BTree
{
	BTreeNode* root;
	size_t t; // minimum degree;
public:
	BTree(size_t _t) : root(nullptr), t(_t)
	{
	};

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
	// tree is empty
	if (root == nullptr)
	{
		root = new BTreeNode(t, true);
		root->keys[0u] = key;
		root->n = 1;
	}
	else // tree is not empty
	{
		//if root is full, then tree grows in height
		if (root->n == 2u * t - 1u)
		{
			// 1. allocate memory for new root
			auto* s = new BTreeNode(t, false);

			// 2. make old root as child of new root
			s->child[0] = root;

			// 3. split the old root and move 1 key the new root
			s->splitchildhild(0u, root);

			// 4. New root has two children now. Decide which of the
			// two children is going to have new key

			auto i = 0u;
			if (s->keys[0] < key)
				++i;

			s->child[i]->insertNonFull(key);

			// 5. change root
			root = s;
		}
		else // if root is not full, just simple put key in tree
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
	//  if it has a child, otherwise set root as NULL
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
