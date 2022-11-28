#include "Graph.h"
#include "DFS_BFS.h"
#include "path.h"

#include <iostream>

int main()
{
	Graph graph;

	// DFS and BFS traversing
	std::cout << "#############################################\n";
	std::cout << "Graph traverse\n";
	std::cout << "#############################################\n";

	graph["a"] = { "b1", "b2" };
	graph["b1"] = { "c1", "c2", "c3" };
	graph["b2"] = { "d1", "d2" };

	std::cout << graph << "\n";

	std::cout << "DFS(a): " << DFS(graph, "a") << "\n";
	std::cout << "BFS(a): " << BFS(graph, "a") << "\n";

	// Directed and Undirected graphs created from a list of edges
	std::cout << "#############################################\n";
	std::cout << "Graph creation from a list of edges\n";
	std::cout << "#############################################\n";
	graph = { { {"a", "b"}, {"b", "c"}}, GraphType::Directed };
	std::cout << "graph 2: " << graph << "\n";

	graph = { { {"a", "b"}, {"b", "c"} }, GraphType::Directed };
	std::cout << "graph 3: " << graph << "\n";

	graph = { { {"a", ""}, {"b", "c"} }, GraphType::Undirected };
	std::cout << "graph 4: " << graph << "\n";

	graph = { { {"a", ""}, {"", "b"} }, GraphType::Undirected };
	std::cout << "graph 5: " << graph << "\n";

	graph = { { {"", ""} }, GraphType::Undirected };
	std::cout << "graph 6: " << graph << "\n";

	// connectivity test
	std::cout << "#############################################\n";
	std::cout << "Connectivity checks\n";
	std::cout << "#############################################\n";
	graph = { { {"a", "b"}, {"b", "c"}}, GraphType::Directed };
	std::cout << "graph: " << graph << "\n";
	std::cout << "path(a, c) = " << path(graph, "a", "c") << "\n";
	std::cout << "path(b, a) = " << path(graph, "b", "a") << "\n";
	std::cout << "path(c, a) = " << path(graph, "c", "a") << "\n";

	graph = { { {"a", "b"}, {"b", "c"}}, GraphType::Undirected };
	std::cout << "graph: " << graph << "\n";
	std::cout << "path(a, c) = " << path(graph, "a", "c") << "\n";
	std::cout << "path(b, a) = " << path(graph, "b", "a") << "\n";
	std::cout << "path(c, a) = " << path(graph, "c", "a") << "\n";

}