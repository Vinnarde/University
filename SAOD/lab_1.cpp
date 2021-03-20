#include <array>
#include <iostream>

/*	–азработать алгоритм и программу переразмещени€ чисел
 *	в некоторой заданной таблице таким образом,
 *	чтобы все отрицательные значени€ предшествовали положительным.
 *	Ёлементы не нужно полностью сортировать;
 *	достаточно просто отделить отрицательные числа от положительных.
 *	јлгоритм должен производить минимальное число обменов.
 */

auto constexpr size = 10;
unsigned counter = 0;


void sort(std::array<int, size>& array)
{
	counter = 0;

	auto low = 0u;
	auto high = array.size() - 1u;
	auto mid = 0u;

	// Iterate till all the elements 
	// are sorted 
	while (mid <= high)
	{
		if (array[mid] < 0)
		{
			if (low == mid)
			{
				low++; mid++;
				continue;
			}
			
			std::swap(array[low++], array[mid++]);
			counter++;
		}
		else if (array[mid] == 0)
		{
			mid++;
		}
		else
		{
			std::swap(array[mid], array[high--]);
			counter++;
		}
	}
}

void printArray(std::array<int, size>& array)
{
	// Iterate and print every element 
	for (auto& x : array)
	{
		std::cout << x << ' ';
	}
}


int main()
{
	srand(time(nullptr));
	std::cout << "This is lab 1!\n";

	std::array<int, size> array{};

	for (auto& x : array)
	{
		x = rand() % 21 - 10;
	}

	std::cout << "Array before sorting:\n";
	printArray(array);

	std::cout << "\n\nSorting....\n\n";

	sort(array);

	std::cout << "Array after sorting:\n";
	printArray(array);

	std::cout << "\nSwap was used for " << counter << " times!\n";


	return 0;
}
