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

int str2int(string binary_str) {
    int a = binary_str.length();
    int sum = 0;
    for (int i = a - 1; i >= 0; i--) {
        sum += (int(binary_str.at(i))-48) * pow(2, (a-i-1));
    }
    return sum;
}
int InvertTree(TreeNode* root, string bin_str) {
    bin_str += std::to_string(root->val);
    int sumL = 0;
    int sumR = 0;
    int sum = 0;
    if (root->left != NULL) {
        sumL = InvertTree(root->left, bin_str);
    }
    if (root->right != NULL) {
        sumR = InvertTree(root->right, bin_str);
    }
    if (root->left == NULL && root->right == NULL){
        sum = str2int(bin_str);
    }
    else{
        sum = sumL + sumR;
    }
    return sum;
}

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int a = InvertTree(root, "");
        return a;
    }
};