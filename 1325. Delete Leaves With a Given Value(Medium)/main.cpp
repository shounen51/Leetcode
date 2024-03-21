/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool findLeaf(TreeNode*& node, int target){
        if (node->left != nullptr){
            if (findLeaf(node->left, target)){
                // delete node->left;
                node->left = nullptr;
            }
        }
        if (node->right != nullptr){
            if (findLeaf(node->right, target)){
                // delete node->right;
                node->right = nullptr;
            }
        }
        if (node->left == nullptr && node->right == nullptr && node->val == target){
            return true;
        }
        return false;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (findLeaf(root, target)){
            if (root->left == nullptr && root->right == nullptr && root->val == target){
                // delete root;
                return nullptr;
            }
        }
        return root;
    }
};