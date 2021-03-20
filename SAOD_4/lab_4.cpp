#include <iostream>

auto constexpr size = 7u;


void depth_first_search(int graph[size][size], bool* visited, int node)
{
	visited[node] = true;
	std::cout << node + 1 << std::endl;
	for (auto i = 0u; i < size; i++)
	{
		if (graph[node][i] && !visited[i])
		{
			depth_first_search(graph, visited, i);
		}
	}
}


int main()
{
	std::cout << "This is lab 4!\n\n";

	// матрица смежности
	int graph[size][size] =
	{
		{ 0, 1, 1, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 0, 0, 0 },
		{ 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 1, 0, 1, 0 },
		{ 0, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 0, 0, 0, 1, 0 }
	};

	bool visited[size] = {};

	depth_first_search(graph, visited, 6);

	return 0;
}
