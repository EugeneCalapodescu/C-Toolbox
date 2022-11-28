#include "path.h"
#include <set>

bool path(const Graph& graph, const std::string& a, const std::string& b, std::set<std::string>& visited)
{
	if (a == b)
		return true;

	if (visited.find(a) != visited.end())
		return false;

	visited.insert(a);

	auto n = graph.nodes.find(a);
	if (n != graph.nodes.end())
	{
		for (auto n : n->second)
		{
			if (path(graph, n, b, visited))
				return true;
		}
	}

	return false;
}

bool path(const Graph& graph, const std::string& a, const std::string& b)
{
	std::set<std::string> visited;
	return path(graph, a, b, visited);
}