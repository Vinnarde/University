#include <iostream>
#include <vector>

uint32_t min_key(std::vector<int>& key, std::vector<bool>& mst_set)
{
	auto min = INT_MAX, min_index = -1;

	for (auto v = 0u; v < key.size(); v++)
	{
		if (mst_set[v] == false && key[v] < min)
		{
			min = key[v];
			min_index = v;
		}
	}
	return min_index;
}

void print_mst(std::vector<int>& parent, std::vector<std::vector<int>>& graph)
{
	auto sum = 0u;
	for (auto i = 1u; i < graph.size(); i++)
	{
		std::cout << "\tEdge: " << static_cast<char>(parent[i] + 'A') << ' ' << static_cast<char>(i + 'A')
			<< ' ' << graph[i][parent[i]] << " \n";
		sum += graph[i][parent[i]];
	}
	std::cout << "Weight: " << sum << '\n';
}


void prim_mst(std::vector<std::vector<int>>& graph)
{
	const size_t size = graph.size();
	std::vector<int> parent(size);

	std::vector<int> key(size);

	std::vector<bool> mst_set(size);

	for (auto i = 0u; i < size; i++)
	{
		key[i] = INT_MAX;
		mst_set[i] = false;
	}

	key[0] = 0;
	parent[0] = -1;

	for (auto count = 0u; count < size - 1; count++)
	{
		auto u = min_key(key, mst_set);
		mst_set[u] = true;

		for (auto v = 0u; v < size; v++)
		{
			if (graph[u][v] && mst_set[v] == false && graph[u][v] < key[v])
			{
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}

	print_mst(parent, graph);
}
