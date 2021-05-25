#pragma once
#include <iostream>

class BTreeNode;

class BTree
{
	BTreeNode* root;	// ������ ������
	size_t t;			// ����������� �������

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
	// ������ ������
	if (root == nullptr)
	{
		root = new BTreeNode(t, true);
		root->keys[0u] = key;
		root->n = 1;
	}
	else // ������ �� ������
	{
		// ���� ������ ��������, �� ��� ������ �������������
		if (root->n == 2u * t - 1u)
		{
			// 1. ��������� ������ ��� ������ �����
			auto* s = new BTreeNode(t, false);

			// 2. ������� ������ ������ ����� ������
			s->child[0] = root;

			// 3. ������� ������ ������ � ����������� 1 ���� � ������ �����
			s->splitChild(0u, root);

			// 4. � ������ ����� ������ ��� ����.
			// ���������� � ������ ���� ����� ����� ����.
			auto i = 0u;
			if (s->keys[0] < key)
				++i;

			s->child[i]->insertNonFull(key);

			// 5. ������ ������
			root = s;
		}
		else // ���� �� ��������, �� ������ ��������� ����
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
