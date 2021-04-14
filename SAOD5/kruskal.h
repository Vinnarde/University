//#pragma once
//#include <algorithm>
//#include <iostream>
//#include <vector>
//
//using i_pair = std::pair<int, int>;
//
//struct graph
//{
//	size_t v, e;
//	std::vector<std::pair<int, i_pair>> edges;
//
//	graph(size_t v, size_t e)
//	{
//		this->v = v;
//		this->e = e;
//	}
//
//	void add_edge(int u, int v, int w)
//	{
//		edges.push_back({w, {u, v}});
//	}
//
//	int kruskal_mst();
//};
//
//// To represent Disjoint Sets
//struct disjoint_sets
//{
//	int *parent, *rank;
//	size_t size;
//
//	disjoint_sets(size_t n)
//	{
//		this->size = n;
//		parent = new int[n + 1];
//		rank = new int[n + 1];
//
//		// Initially, all vertices are in
//		// different sets and have rank 0.
//		for (auto i = 0; i <= size; i++)
//		{
//			rank[i] = 0;
//
//			//every element is parent of itself
//			parent[i] = i;
//		}
//	}
//
//	// Find the parent of a node 'u'
//	// Path Compression
//	int find(int u)
//	{
//		/* Make the parent of the nodes in the path
//		from u--> parent[u] point to parent[u] */
//		if (u != parent[u])
//			parent[u] = find(parent[u]);
//		return parent[u];
//	}
//
//	// Union by rank
//	void merge(int x, int y)
//	{
//		x = find(x), y = find(y);
//
//		/* Make tree with smaller height
//		a subtree of the other tree */
//		if (rank[x] > rank[y])
//			parent[y] = x;
//		else // If rank[x] <= rank[y]
//			parent[x] = y;
//
//		if (rank[x] == rank[y])
//			rank[y]++;
//	}
//};
//
//
//int graph::kruskal_mst()
//{
//	auto mst_wt = 0u; // Initialize result
//
//	// Sort edges in increasing order on basis of cost
//	sort(edges.begin(), edges.end());
//
//	// Create disjoint sets
//	disjoint_sets ds(v);
//
//	// Iterate through all sorted edges
//	//std::vector<std::pair<int, i_pair>>::iterator it;
//	for (auto& edge : edges)
//	{
//		auto u = edge.second.first;
//		auto v = edge.second.second;
//
//		auto set_u = ds.find(u);
//		auto set_v = ds.find(v);
//
//
//		if (set_u != set_v)
//		{
//			std::cout << u << " - " << v << std::endl;
//
//			mst_wt += edge.first;
//
//			ds.merge(set_u, set_v);
//		}
//	}
//
//	return mst_wt;
//}
//
////int main()
////{
////
////	int V = 9, E = 14;
////	graph g(V, E);
////
////	// making above shown graph
////	g.add_edge(0, 1, 4);
////	g.add_edge(0, 7, 8);
////	g.add_edge(1, 2, 8);
////	g.add_edge(1, 7, 11);
////	g.add_edge(2, 3, 7);
////	g.add_edge(2, 8, 2);
////	g.add_edge(2, 5, 4);
////	g.add_edge(3, 4, 9);
////	g.add_edge(3, 5, 14);
////	g.add_edge(4, 5, 10);
////	g.add_edge(5, 6, 2);
////	g.add_edge(6, 7, 1);
////	g.add_edge(6, 8, 6);
////	g.add_edge(7, 8, 7);
////
////	std::cout << "Edges of MST are \n";
////	int mst_wt = g.kruskal_mst();
////
////	std::cout << "\nWeight of MST is " << mst_wt;
////
////	return 0;
////}
