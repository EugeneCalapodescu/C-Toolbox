#include "BinaryTree.h"

#include <iostream>

template<typename T>
void print(std::vector<T> vec)
{
	std::cout << "[";
	for (auto& v : vec)
		std::cout << v << " ";

	std::cout << "]";
}

int main()
{
	BinaryTree<int> *root = new BinaryTree<int>(4);
	
	root->left = new BinaryTree<int>(2);
	root->left->left = new BinaryTree<int>(1);
	root->left->right = new BinaryTree<int>(3);
		
	root->right = new BinaryTree<int>(6);
	root->right->left = new BinaryTree<int>(5);
	root->right->right = new BinaryTree<int>(7);

	std::vector<int> nodes;

	std::cout << "DFS\n";
	dfs(root, nodes);
	print(nodes);
	std::cout << "\n";

	std::cout << "BFS\n";
	nodes.clear();
	bfs(root, nodes);
	print(nodes);
	std::cout << "\n";

	std::cout << "BFS by level\n";
	std::vector<std::vector<int>> levels;

	bfs_by_level(root, levels);

	for (auto& v : levels)
	{
		print(v);
		std::cout << "\n";
	}

}