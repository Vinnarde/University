#include <iostream>
#include <array>
#include <list>

struct HashNode
{
	char letter;
	uint32_t counter;

	bool operator == (char ch)
	{
		return ch == letter;
	}
	HashNode operator = (HashNode& otherHashNode)
	{
		HashNode temp;
		temp.counter = otherHashNode.counter;
		temp.letter = otherHashNode.letter;
		return temp;
	}
	HashNode(char ch)
	{
		letter = ch;
		counter = 1u;
	}

	HashNode()
	{
	}
};

class HashTable
{
	static const size_t size = 26;
	std::array<std::list<HashNode>, size> table;

	int hashFunction(char letter)
	{
		return (letter - 'a') % size;
	}
public:

	void insertItem(char letter);
	void deleteItem(char letter);

	bool searchItem(char letter);
	void printTable();

};

void HashTable::insertItem(char letter)
{
	// 1. Calculate hash-index
	size_t index = hashFunction(letter);

	auto it = std::find(table[index].begin(), table[index].end(), letter);

	// 2. If letter already in table, then increase counter by 1
	if (it != table[index].end())
	{
		it->counter++;
	}
	// 3. Else insert new letter in table
	else
	{
		/*HashNode temp;
		temp.counter = 1;
		temp.letter = letter;*/
		table[index].push_back(HashNode(letter));
	}
}

void HashTable::deleteItem(char letter)
{
}

bool HashTable::searchItem(char letter)
{
	size_t index = hashFunction(letter);

	auto it = std::find(table[index].begin(), table[index].end(), letter);
	return it != table[index].end();
}

void HashTable::printTable()
{
	for (size_t index = 0; index < size; ++index)
	{
		std::cout << index << ":\t";
		for (auto it = table[index].begin(); it != table[index].end(); ++it)
		{
			std::cout << "(" << it->letter << "; " << it->counter << "), ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	std::cout << "This is lab 3!\n";

	HashTable table;

	std::string text = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiop[]asdfghjkl;'zxcvbnm,./";
	for (auto x : text)
	{
		if (std::isalpha(x))
			table.insertItem(std::tolower(x));

		//table.insertItem(x);
	}

	table.printTable();


	std::cout << "Searching for 'A': " << table.searchItem('A') << '\n';
	std::cout << "Searching for 'a': " << table.searchItem('a') << '\n';

	return 0;
}


