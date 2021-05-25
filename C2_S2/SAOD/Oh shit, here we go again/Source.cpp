#include <iostream>
#include <utility>
#include <vector>


#include "BTreeNode.hpp"
#include "btree.hpp"


int main()
{
	BTree t(2); // A B-Tree with minimum degree 2
	t.insert(5);
	t.insert(9);
	t.insert(3);
	t.insert(7);
	t.insert(1);
	t.insert(2);
	t.insert(8);
	t.insert(6);
	t.insert(0);
	
	std::cout << "Traversal of the constructed tree is \n";
	t.traverse();

	t.insert(4);
	std::cout << "After inserting 4: \n";
	t.traverse();
	
	std::cout << "After removing 9: \n";
	
	t.remove(9);

	t.traverse();

	//std::cout << "After removing 13: \n";
	//
	//t.remove(13);
	//t.traverse();

	return 0;
}
