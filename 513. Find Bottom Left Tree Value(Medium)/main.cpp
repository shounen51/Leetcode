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
class Solution {
public:
    queue<TreeNode*> bfsQueue;
    int findBottomLeftValue(TreeNode* root) {
        bfsQueue.push(root);
        int thisLayerNode = 1;
        int nextLayerNode = 0;
        int bottomLeftNode = root->val;
        while(bfsQueue.size()>0){
            TreeNode* n = bfsQueue.front();
            bfsQueue.pop();
            if(n->left != nullptr){
                bfsQueue.push(n->left);
                nextLayerNode++;
            }
            if(n->right != nullptr){
                bfsQueue.push(n->right);
                nextLayerNode++;
            }
            if(--thisLayerNode == 0){
                thisLayerNode = nextLayerNode;
                nextLayerNode = 0;
                if(bfsQueue.size()>0){
                    bottomLeftNode = bfsQueue.front()->val;
                }
            }
        }
        return bottomLeftNode;
    }
};