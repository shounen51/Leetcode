這題也應該歸類在Easy
給一正整數陣列nums，把裡面每一個正整數的位數反轉(123 -> 321)後加在陣列後方，返回該陣列最後有幾種不同的數字

Example 1:
Input: nums = [1,13,10,12,31]
Output: 6
Explanation: After including the reverse of each number, the resulting array is [1,13,10,12,31,1,31,1,21,13].
The reversed integers that were added to the end of the array are underlined. Note that for the integer 10, after reversing it, it becomes 01 which is just 1.
The number of distinct integers in this array is 6 (The numbers 1, 10, 12, 13, 21, and 31).

Example 2: 
Input: nums = [2,2,2]
Output: 1
Explanation: After including the reverse of each number, the resulting array is [2,2,2,2,2,2].
The number of distinct integers in this array is 1 (The number 2).

Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 106

我的解法：
我選擇用較簡單的方法利用字串反轉去做，先把nums每一個數字轉字串、反轉、轉回int、放到陣列後面
然後把陣列轉set去除掉重複元素，回傳set長度
C++ code:
```c++
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int len = nums.size();
        for (int i=0; i<len; i++){
            int num = nums[i];
            string numString = to_string(num);
            reverse(numString.begin(), numString.end());
            int reversedNum = stoi(numString);
            nums.push_back(reversedNum);
        }
        set<int> numsSet(nums.begin(), nums.end());
        return numsSet.size();
    }
};
```
速度不快，但簡單好寫
寫完才發現他有Math標籤，反轉的部分應該要用數學解，但一直%10*10不曉得有沒有比較快