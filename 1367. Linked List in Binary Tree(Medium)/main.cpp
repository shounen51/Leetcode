/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool findSubPath(vector<ListNode*> candidateNode, ListNode* head, TreeNode* nodeT){
        int v = nodeT->val;
        for (int i = candidateNode.size() - 1; i >= 0; i--){
            if (v == candidateNode[i]->val){
                if (candidateNode[i]->next == nullptr) return true;
                else candidateNode[i] = candidateNode[i]->next;
            }else{
                candidateNode.erase(candidateNode.begin()+i);
            }
        }
        if (v == head->val){
            if (head->next == nullptr) return true;
            else{
                ListNode* temp = head->next;
                candidateNode.push_back(temp);
            }
        }
        if (nodeT->left != nullptr){
            if (findSubPath(candidateNode, head, nodeT->left)) return true;
        }
        if (nodeT->right != nullptr){
            if (findSubPath(candidateNode, head, nodeT->right)) return true;
        }
        return false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<ListNode*> candidateNode;
        return findSubPath(candidateNode, head, root);
    }
};