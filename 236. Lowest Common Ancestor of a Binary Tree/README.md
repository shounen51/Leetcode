Companies
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
求一棵樹中某兩個點的最近共同祖先(LCA)，祖先就是從自己往上走的所有點(含自己)
 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.

我的解：
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool findPath(TreeNode* root, vector<TreeNode*>* path, TreeNode* target){
        path->push_back(root);
        if (root->val == target->val) return true;
        if (root->left != NULL){
            bool END = findPath(root->left, path, target);
            if (END) return END;
        }
        if (root->right != NULL){
            bool END = findPath(root->right, path, target);
            if (END) return END;
        }
        path->pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath = {};
        vector<TreeNode*> qPath = {};
        findPath(root, &pPath, p);
        findPath(root, &qPath, q);
        TreeNode* ans;
        for (int i=0; i<pPath.size()&&i<qPath.size(); i++){
            if (pPath[i]!=qPath[i]) break;
            else ans = qPath[i];
        }
        return ans;
    }
};
```
解題思路：
先把兩個點的路徑找出來，這個之前有Easy的題目做過(257)
然後把兩條路徑比對一下，找最深的相同點

第一次提交的時候給他記憶體用爆了，因為我在遞迴的時候path是傳值，深度很深的時候stack會爆滿，改傳址就OK了，真的是python寫太久了...