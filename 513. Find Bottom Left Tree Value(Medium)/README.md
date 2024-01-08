513. Find Bottom Left Tree Value
Medium

Given the root of a binary tree, return the leftmost value in the last row of the tree.

給一個樹，回傳最深層的最左邊的node的value

這題我使用廣度搜尋法，同時為了知道哪顆是最後一層的最左邊我用了兩個int紀錄當層的node數量以及下一層的node數量，每當切換到下一層的時候把第一個node記錄起來就是答案了

不過這題我是被預設的搜尋框架綁住了，只要由右到左做bfs的話就不用那麼麻煩，最後一顆就一定是答案。
```c++
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
```