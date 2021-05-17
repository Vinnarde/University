#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

/*
 * Составить программу поиска минимального остовного дерева по алгоритму Прима, Краскала, Прима – Краскала.
 * Оценить эффективность на различных примерах.
 */

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

#pragma region kruskal

using i_pair = std::pair<int, int>;

struct graph
{
	size_t v, e;
	std::vector<std::pair<int, i_pair>> edges;

	graph(size_t v, size_t e)
	{
		this->v = v;
		this->e = e;
	}

	void add_edge(int u, int v, int w)
	{
		edges.push_back({ w, {u, v} });
	}

	int kruskal_mst();
};

// To represent Disjoint Sets
struct disjoint_sets
{
	int* parent, * rank;
	size_t size;

	disjoint_sets(size_t n)
	{
		this->size = n;
		parent = new int[n + 1];
		rank = new int[n + 1];

		for (auto i = 0u; i <= size; i++)
		{
			rank[i] = 0;
			parent[i] = i;
		}
	}

	int find(int u)
	{
		if (u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}

	void merge(int x, int y)
	{
		x = find(x), y = find(y);

		
		if (rank[x] > rank[y])
			parent[y] = x;
		else 
			parent[x] = y;

		if (rank[x] == rank[y])
			rank[y]++;
	}
};

int graph::kruskal_mst()
{
	auto mst_wt = 0u; 

	// Sort edges in increasing order on basis of cost
	std::sort(edges.begin(), edges.end());

	// Create disjoint sets
	disjoint_sets ds(v);

	// Iterate through all sorted edges
	for (auto& edge : edges)
	{
		const auto u = edge.second.first;
		const auto v = edge.second.second;
		const auto w = edge.first;

		const auto set_u = ds.find(u);
		const auto set_v = ds.find(v);


		if (set_u != set_v)
		{
			std::cout << "\t Edge: " << static_cast<char>(u + 'A') << ' ' << static_cast<char>(v + 'A') << ' ' << w << std::endl;

			mst_wt += edge.first;

			ds.merge(set_u, set_v);
		}
	}

	return mst_wt;
}
#pragma endregion kruskal

void prim_mst(std::vector<std::vector<int>>& graph);

uint32_t prim_kruskal(std::vector<std::pair<bool, std::vector<int>>>& matrix)
{
	auto mst_weight = 0;
	for (auto k = 0u; k < matrix.size() - 1; ++k)
	{
		auto min = INT32_MAX;
		auto row_min(-1), column_min(-1);

		// 1. Finding min element in selected rows or in matrix if it's first iteration.
		for (auto i = 0u; i < matrix.size(); ++i)
		{
			for (auto j = 0u; j < matrix.size(); ++j)
			{
				if (k == 0)
				{
					if (matrix[i].second[j] > 0)
					{
						if (matrix[i].second[j] < min)
						{
							min = matrix[i].second[j];
							row_min = i;
							column_min = j;
						}
					}
				}
				else
				{
					if (matrix[i].second[j] > 0 && matrix[i].first)
					{
						if (matrix[i].second[j] < min)
						{
							min = matrix[i].second[j];
							row_min = i;
							column_min = j;
						}
					}
				}
			}
		}

		// 2. Mark i,j row
		matrix[row_min].first = matrix[column_min].first = true;

		// 3. Clear i and j column, except min element.

		for (auto& i : matrix)
		{
			i.second[row_min] = i.second[column_min] = 0;
		}

		mst_weight += min;
		std::cout << "\tEdge: " << static_cast<char>(row_min + 'A') << ' ' << static_cast<char>(column_min + 'A') << ' '
			<< min << '\n';
	}
	return mst_weight;
}

int main()
{
	size_t num_of_vertices, num_of_edges;
	std::cout << "Enter number of vertices: ";
	std::cin >> num_of_vertices;
	std::cout << "Enter number of edges: ";
	std::cin >> num_of_edges;

	std::vector<std::pair<bool, std::vector<int>>> matrix_1; // prim-kruskal
	std::vector<std::vector<int>> matrix_2(num_of_vertices, std::vector<int>(num_of_vertices)); // prim
	graph graph(num_of_vertices, num_of_edges);

	matrix_1.resize(num_of_vertices);
	for (auto& x : matrix_1)
		x.second.resize(num_of_vertices);

	for (auto i = 0u; i < num_of_vertices; ++i)
	{
		matrix_1[i].first = false;
		for (auto j = 0u; j < num_of_vertices; ++j)
		{
			matrix_1[i].second[j] = 0;
			matrix_2[i][j] = 0;
		}
	}

	std::cout << "Enter edges in format: A B length\n";
	for (auto i = 0u; i < num_of_edges; ++i)
	{
		std::cout << "Enter edge #" << i + 1 << ": ";
		char edge_1_temp, edge_2_temp;
		uint32_t length;
		std::cin >> edge_1_temp >> edge_2_temp >> length;

		const uint32_t edge_1 = edge_1_temp - 'A';
		const uint32_t edge_2 = edge_2_temp - 'A';

		matrix_1[edge_1].second[edge_2] = matrix_1[edge_2].second[edge_1] = length;
		matrix_2[edge_1][edge_2] = matrix_2[edge_2][edge_1] = length;
		graph.add_edge(edge_1, edge_2, length);
	}

	for (auto i = 0u; i < num_of_vertices; ++i)
	{
		for (auto j = 0u; j < num_of_vertices; ++j)
		{
			std::cout << matrix_1[i].second[j] << ' ';
		}
		std::cout << '\n';
	}

	std::cout << "\nResult:\n" << "1. Prim-Kruskal's algorithm:\n";
	Timer t;
	std::cout << "Minimum spanning tree weight is " << prim_kruskal(matrix_1) << '\n';
	std::cout << "Time taken: " << t.elapsed() << "\n\n";
	std::cout << "2. Prim's algorithm: \n";
	t.reset();
	prim_mst(matrix_2);
	std::cout << "Time taken: " << t.elapsed() << "\n\n";
	std::cout << "3. Kruskal's algorithm: \n";
	t.reset();
	std::cout << "Weight: " << graph.kruskal_mst() <<'\n';
	std::cout << "Time taken: " << t.elapsed() << "\n\n";
}


//auto mst_weight = 0;
//for (auto k = 0u; k < num_of_vertices - 1; ++k)
//{
//	auto min = INT32_MAX;
//	auto row_min(-1), column_min(-1);

//	// 1. Finding min element in selected rows or in matrix if it's first iteration.
//	for (auto i = 0u; i < num_of_vertices; ++i)
//	{
//		for (auto j = 0u; j < num_of_vertices; ++j)
//		{
//			if (k == 0)
//			{
//				if (matrix_1[i].second[j] > 0)
//				{
//					if (matrix_1[i].second[j] < min)
//					{
//						min = matrix_1[i].second[j];
//						row_min = i;
//						column_min = j;
//					}
//				}
//			}
//			else
//			{
//				if (matrix_1[i].second[j] > 0 && matrix_1[i].first)
//				{
//					if (matrix_1[i].second[j] < min)
//					{
//						min = matrix_1[i].second[j];
//						row_min = i;
//						column_min = j;
//					}
//				}
//			}
//		}
//	}

//	// 2. Mark i,j row
//	matrix_1[row_min].first = matrix_1[column_min].first = true;

//	// 3. Clear i and j column, except min element.

//	for (auto i = 0u; i < num_of_vertices; ++i)
//	{
//		matrix_1[i].second[row_min] = matrix_1[i].second[column_min] = -1;
//	}

//	mst_weight += min;
//	std::cout << "Edge: " << static_cast<char>(row_min + 'A') << ' ' << static_cast<char>(column_min + 'A') << ' '
//		<< min << '\n';
//}