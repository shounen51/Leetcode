給一個正整數n(long long)和target(int)
幫n加上一個正整數x(long long)使得n的每一個位數加總小於等於target，沒有無解的題目
求最小的x

Example 1:
Input: n = 16, target = 6
Output: 4
Explanation: Initially n is 16 and its digit sum is 1 + 6 = 7. After adding 4, n becomes 20 and digit sum becomes 2 + 0 = 2. It can be shown that we can not make n beautiful with adding non-negative integer less than 4.
Example 2:

Input: n = 467, target = 6
Output: 33
Explanation: Initially n is 467 and its digit sum is 4 + 6 + 7 = 17. After adding 33, n becomes 500 and digit sum becomes 5 + 0 + 0 = 5. It can be shown that we can not make n beautiful with adding non-negative integer less than 33.
Example 3:

Input: n = 1, target = 1
Output: 0
Explanation: Initially n is 1 and its digit sum is 1, which is already smaller than or equal to target.

Constraints:

1 <= n <= 10^12
1 <= target <= 150

我的想法：
每一個位數都可以透過加法進位被轉換成0，比方說16的個位數6加上4就會變成0，而十位數會變成1+1，透過這個操作就會讓原本的位數加總7變成 7-6(個位數變成0)+1(個位數進位)=2，因為要求最小的x，所以這個操作從個位數開始往上進行

C++ code:
```c++
class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        n--; 
        string sn = to_string(n);
        int total = 1;
        for (int i=0; i<sn.length(); i++){
            total += sn[i] - '0';
        }
        string patch = "";
        for (int i=sn.length()-1; i>=0; i--){
            if(total <= target) break;
            int current = (sn[i]-'0')+1;
            total -= current-1;
            patch.insert(0, to_string(10-current));
        }
        if (patch.length()==0){
             patch.append(1, '0');
        }
        long long ans = stoll(patch);
        return ans;
    }
};
```
首先計算當前的位數加總
接著從個位數開始操作直到達成條件，首先因為上一個位數有進位的關係把當前的位數+1，然後進行操作後位數加總會減少current-1，接著答案的部份加上當前位數的10的補數
計算到每一個位數都會進行+1(上一個位數的進位)，除了個位數
為了寫起來方便我先做一次n-1，這樣讓for迴圈裡面可以無條件的+1，而不用為了個位數的例外去寫一個判斷
total的初始化是1也是因為我先-1了
