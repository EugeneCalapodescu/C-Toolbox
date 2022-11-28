#include "DFS_BFS.h"
#include <sstream>
#include <stack>
#include <queue>

std::string DFS(const Graph& graph, const std::string& start)
{
	std::stringstream str;
	std::stack<std::string> stack;

	stack.push(start);
	while (!stack.empty())
	{
		std::string top = stack.top();
		stack.pop();

		str << top << " ";

		auto neighbours = graph.nodes.find(top);
		if (neighbours != graph.nodes.end())
			for (std::string n : neighbours->second)
				stack.push(n);
	}

	return str.str();
}


std::string BFS(const Graph& graph, const std::string& start)
{
	std::stringstream str;
	std::queue<std::string> queue;

	queue.push(start);
	while (!queue.empty())
	{
		std::string top = queue.front();
		queue.pop();

		str << top << " ";

		auto neighbours = graph.nodes.find(top);
		if (neighbours != graph.nodes.end())
			for (std::string n : neighbours->second)
				queue.push(n);
	}

	return str.str();
}