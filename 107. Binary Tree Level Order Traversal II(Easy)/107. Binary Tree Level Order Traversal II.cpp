/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*繼承上一題的深度探索，需要用以宣告vector的長度*/
void find_tree_depth(TreeNode* pointer_tree, int depth_N, int* depth_G) {
    depth_N++;
    if (depth_N > * depth_G) {
        *depth_G = depth_N;
    }
    if (pointer_tree->left != NULL) {
        find_tree_depth(pointer_tree->left, depth_N, depth_G);
    }
    if (pointer_tree->right != NULL) {
        find_tree_depth(pointer_tree->right, depth_N, depth_G);
    }
}
/*以前序走訪二元樹，將每個值存於vector*/
void treelevel(TreeNode* pointer_tree, int level, vector<vector<int>>::iterator iterator_ans) {
    iterator_ans[level].push_back(pointer_tree->val);
    level--;
    if (pointer_tree->left != NULL) {
        treelevel(pointer_tree->left, level, iterator_ans);
    }
    if (pointer_tree->right != NULL) {
        treelevel(pointer_tree->right, level, iterator_ans);
    }
}
/*這個是main*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int depth = 0;
        int* depth_G = &depth;
        　/*取得二元樹深度*/
        if (root != NULL) {
            TreeNode* pointer = root;
            find_tree_depth(pointer, 0, depth_G);
        }
        　/*在if()範圍外宣告vector以及其iterator*/
        vector<vector<int>> ans(depth);
        vector<vector<int>>::iterator iterator_ans = ans.begin();
        　/*走訪二元樹*/
        if (root != NULL) {
            TreeNode* pointer = root;
            treelevel(pointer, depth - 1, iterator_ans);
        }
        return ans;
    }
};