#include <stack>
#include <queue>
#include "Graph.h"
#include <iostream>
#include <sstream>

std::ostream& operator<<(std::ostream& os, const Graph& graph)
{
	os << "{\n";
	for (auto node : graph.nodes)
	{
		os << node.first << ":\t {";

		for (auto neighbour : node.second)
			os << neighbour << " ";

		os << "}\n";
	}
	os << "}";

	return os;
}

Graph::Graph(const std::vector<std::pair<std::string, std::string>>& edges, GraphType type)
{
	nodes.clear();

	for (auto edge : edges)
	{
		if (!edge.first.empty())
		{
			auto it = nodes.find(edge.first);
			if (it == nodes.end())
				nodes.insert({ edge.first, {} });

			if (!edge.second.empty())
				nodes[edge.first].push_back(edge.second);
		}

		if (!edge.second.empty())
		{
			auto it = nodes.find(edge.second);
			if (it == nodes.end())
				nodes.insert({ edge.second, {} });

			if(type == GraphType::Undirected && !edge.first.empty())
				nodes[edge.second].push_back(edge.first);
		}

	}
}
