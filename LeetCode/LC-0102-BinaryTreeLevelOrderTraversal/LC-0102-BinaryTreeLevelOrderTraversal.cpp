/*

	LC 102 Binary Tree Level Order Traversal

	Given the root of a binary tree, return the level order traversal of its nodes' values. 
	(i.e., from left to right, level by level).

	Example 1:
		Input: root = [3, 9, 20, null, null, 15, 7]
		Output : [[3], [9, 20], [15, 7]]

	Example 2 :
		Input : root = [1]
		Output : [[1]]

*/

#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) 
{
	if (root == NULL) 
		return {};

	vector<vector<int>> res;

	queue<TreeNode*> queue;
	queue.push(root);

	while (! queue.empty())
	{
		int N = queue.size();
		vector<int> level;

		for (int i = 0; i < N; i++) 
		{
			TreeNode* node = queue.front();
			queue.pop();
		
			level.push_back(node->val);

			if (node->left != NULL)
				queue.push(node->left);

			if (node->right != NULL)
				queue.push(node->right);
		}

		res.push_back(level);
	}

	return res;
}

int main()
{
	TreeNode* root = new TreeNode(3);

	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	auto result = levelOrder(root);
}