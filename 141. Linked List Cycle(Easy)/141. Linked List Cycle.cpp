/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        int val = INT_MAX;　//設置一個值，使鏈結中所有值都等於它
        if (head == NULL) {
            return 0;
        }
        while (1)
        {
            　　/*如果節點的值等於所設置的值表示鏈結串列有迴圈*/
            if (head->val != val) {
                head->val = val;
            }
            else {
                return 1;
            }
            　　/*如果鏈結串列有終點則表示沒有迴圈*/
            if (head->next != NULL) {
                head = head->next;
            }
            else {
                return 0;
            }
        }
    }
};