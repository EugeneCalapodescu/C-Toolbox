#pragma once

#include <vector>
#include <stack>
#include <queue>

template <typename T>
struct BinaryTree
{
	T val;
	BinaryTree<T> *left;
	BinaryTree<T> *right;

	BinaryTree(T t) : val(t), left(nullptr), right(nullptr) {};
	BinaryTree(T t, BinaryTree<T>* l, BinaryTree<T>* r) : val(t), left(t), right(r) {};
	virtual ~BinaryTree() 
	{
		delete left;
		delete right;
	}
};

template <typename T>
void dfs(const BinaryTree<T>* root, std::vector<T>& res)
{
	if (root == nullptr)
		return;

	dfs(root->left, res);
	res.push_back(root->val);
	dfs(root->right, res);
}

template <typename T>
void bfs(BinaryTree<T>* root, std::vector<T>& res)
{
	if (root == nullptr)
		return;

	std::queue< BinaryTree<T>* > queue;
	queue.push(root);

	while (!queue.empty())
	{
		auto top = queue.front();
		queue.pop();

		res.push_back(top->val);

		if (top->left)
			queue.push(top->left);

		if (top->right)
			queue.push(top->right);
	}
}

template <typename T>
void bfs_by_level(BinaryTree<T>* root, std::vector<std::vector<T>>& res)
{
	if (root == nullptr)
		return;

	std::queue< BinaryTree<T>* > queue;
	queue.push(root);

	while (!queue.empty())
	{
		int N = (int) queue.size();

		std::vector<T> level;

		for (int i = 0; i < N; i++)
		{
			auto node = queue.front();
			queue.pop();

			level.push_back(node->val);

			if (node->left != NULL)
				queue.push(node->left);

			if (node->right != NULL)
				queue.push(node->right);
		}

		res.push_back(level);
	}
}



