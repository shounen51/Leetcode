/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void addstree(TreeNode* tree, int val, int& ans, int goal) {
	val += tree->val;
	if (val == goal) {
		ans++;
	}
	if (tree->left != NULL) {
		addstree(tree->left, val, ans, goal);
	}
	if (tree->right != NULL) {
		addstree(tree->right, val, ans, goal);
	}
}
void treehead(TreeNode* tree, int& ans, int goal) {
	int val = tree->val;
	if (val == goal) {
		ans++;
	}
	if (tree->left != NULL) {
		addstree(tree->left, val, ans, goal);
		treehead(tree->left, ans, goal);
	}
	if (tree->right != NULL) {
		addstree(tree->right, val, ans, goal);
		treehead(tree->right, ans, goal);
	}
}

class Solution {
public:
	int pathSum(TreeNode* root, int goal) {
		int ans = 0;
		if (root != NULL) {
			treehead(root, ans, goal);
		}
		return ans;
	}
};