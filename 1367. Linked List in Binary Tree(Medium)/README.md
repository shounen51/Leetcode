1367. Linked List in Binary Tree
Medium
Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

給一棵二元樹和一個鏈結串列，回傳樹中是否包含連結串列，其中包含的方始僅限於往下

Example 1:
Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
![](https://assets.leetcode.com/uploads/2020/02/12/sample_1_1720.png)

我的解：
簡單的思維就是把head加到深度搜尋法裡面，當val相同的時候就head->next再接著走，不同的時候就回到head，但是這會遇到一個問題
假設head=[12123]，root有一條[1212123]
這樣答案應該是ture，因為root尾有包含12123
但依上述的方法會在樹的第三個1的地方才發現不合而重回到head，然後就只能匹配到123而不是12123，所以我用vector<ListNode\*>來紀錄目前的匹配狀態，每當當前val相同的時候都新增一個匹配紀錄進去，不同的時候就刪除
所以當運行到樹的第二個1的時候vector除了有前一個listNode的第二個1之外還有一個新的ListNode是第一個1，以此方法來抓漏

此外還有看到另外一種抓漏的方法：
```c++
class Solution {
public:
    bool find(ListNode* head, TreeNode* root) {
        if (head == NULL)
            return true;
        if (root == NULL)
            return false;
        if (head->val == root->val)
            return find(head->next, root->left) ||
                   find(head->next, root->right);
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == NULL)
            return false;
        if (find(head, root))
            return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
```
關鍵在最後一行`return isSubPath(head, root->left) || isSubPath(head, root->right);`
他把頭給拔掉之後分成左樹右樹從頭再來一遍，依上面的例子就是1212123被拔兩次之後就會剩下12123，所以就也會抓到，據統計這個方法會更快