#include <iostream>
#include <fstream>
#include <vector>

constexpr int m = 8;

using i_pair = std::pair<int, int>;

/*
 * Создать индексный файл для файла записей отсортированный по некоторому ключевому полю,
 * запоминая индекс каждой М-ой записи. Организовать главный индекс в оперативной памяти,
 * запоминая доступ к каждой М-ой записи индексного файла.
 * Обеспечить выдачу записи с заданным ключевым путем последовательного поиска
 * в главном индексе и бинарного поиска в индексном файле.
 *
 */

int main()
{
	std::cout << "This is lab 2!\n";
	//std::ofstream file("input.txt");	

	//for (int i = 0; i < 200; ++i)
	//{
	//	file << i * 5 + i % 5 <<  '\n';
	//}


	std::vector<int> table;

	std::ifstream input("input.txt");

	if (input.is_open())
	{
		std::cout << "Reading data:\n";
	}

	while (!input.eof())
	{
		int value;
		input >> value;
		std::cout << value << "\n";
		table.emplace_back(value);
	}

	std::vector<i_pair> index_file;

	for (auto i = 0u; i < table.size(); i += m)
	{
		index_file.emplace_back(std::make_pair(table[i], i));
	}

	std::vector<i_pair> main_index;

	for (auto i = 0u; i < index_file.size(); i += m)
	{
		main_index.emplace_back(std::make_pair(index_file[i].first, i));
	}

	std::cout << "Index file: \n";
	for (auto& x : index_file)
	{
		std::cout << x.first << ' ' << x.second << '\n';
	}

	std::cout << "\nMain index: \n";
	for (auto& x : main_index)
	{
		std::cout << x.first << ' ' << x.second << '\n';
	}

	int value = 131;

	int index = -1;

	// 1. Searching in main index:
	for (auto i = 0u; i < main_index.size(); ++i)
	{
		if (value >= main_index[i].first)
			index = i;
	}

	if (index == -1)
	{
		std::cout << value << "isn't contained in data!\n";
		return 0;
	}

	// 2. Searching in index file using binary search.

	int low = index;
	int high = index + m - 1;
	int mid = -1;
	while (low < high)
	{
		mid = (high + low) / 2;

		if (value > index_file[mid].first)
		{
			low = mid;
		}
		else if (value < index_file[mid].first)
		{
			high = mid;
		}
		else
		{
			index = index_file[mid].second;
			break;
		}

		if ((high - low) == 1)
		{
			index = index_file[low].second;
			break;
		}
	}


	if (index == -1)
	{
		std::cout << value << "isn't contained in data!\n";
		return 0;
	}

	bool found = false;

	for (auto i = index; i < index + m; ++i)
	{
		if (value == table[i])
		{
			found = true;
			break;
		}
	}

	std::cout << found;

	return 0;
}
