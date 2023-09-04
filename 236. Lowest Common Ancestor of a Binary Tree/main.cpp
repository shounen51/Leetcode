#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
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
int main(){
    Solution s;
    // s.lowestCommonAncestor();
    return 0;
}