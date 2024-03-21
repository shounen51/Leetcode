1325. Delete Leaves With a Given Value
Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).

給一棵二元樹，把指定值的葉子都刪除，需連刪

Example 3:
Input: root = [1,2,null,2,null,2], target = 2
Output: [1]
Explanation: Leaf nodes in green with value (target = 2) are removed at each step.
![](https://assets.leetcode.com/uploads/2020/01/15/sample_3_1684.png)

我的解：
這題很單純，用深度搜尋抓葉子，然後判斷條件刪掉，就醬