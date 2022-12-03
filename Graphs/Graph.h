#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <map>
#include <strstream>

enum class GraphType
{
	Directed, Undirected
};

class Graph
{
public:
	std::map<std::string, std::vector<std::string>> nodes;

	Graph() = default;

	// create a graph from a list of edges, eg { {"a", "b"}, { "b", "c" }, { "c", "a"} }
	// an edge like {"x", ""} means a node with no connections
	Graph(const std::vector<std::pair<std::string, std::string>>& edges, GraphType type);

	std::vector<std::string>& operator[](std::string s)
	{
		return nodes[s];
	}

	friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
};

#endif
