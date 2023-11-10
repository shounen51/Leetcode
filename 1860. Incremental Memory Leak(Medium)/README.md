給兩個int代表兩條記憶體的剩餘空間，一個程式每秒會要求配置這兩條記憶體的空間，規則如下
1. 程式第i秒會要求i的空間
2. 系統會優先配置剩餘空間較大的那條記憶體，相同時配置第一條
回一個vector內含三個數字
1. 第幾秒時記憶體會不夠
2. 此時第一條記憶體剩餘的空間
3. 此時第二條記憶體剩餘的空間

Example 1:

Input: memory1 = 2, memory2 = 2
Output: [3,1,0]
Explanation: The memory is allocated as follows:
- At the 1st second, 1 bit of memory is allocated to stick 1. The first stick now has 1 bit of available memory.
- At the 2nd second, 2 bits of memory are allocated to stick 2. The second stick now has 0 bits of available memory.
- At the 3rd second, the program crashes. The sticks have 1 and 0 bits available respectively.
Example 2:

Input: memory1 = 8, memory2 = 11
Output: [6,0,4]
Explanation: The memory is allocated as follows:
- At the 1st second, 1 bit of memory is allocated to stick 2. The second stick now has 10 bit of available memory.
- At the 2nd second, 2 bits of memory are allocated to stick 2. The second stick now has 8 bits of available memory.
- At the 3rd second, 3 bits of memory are allocated to stick 1. The first stick now has 5 bits of available memory.
- At the 4th second, 4 bits of memory are allocated to stick 2. The second stick now has 4 bits of available memory.
- At the 5th second, 5 bits of memory are allocated to stick 1. The first stick now has 0 bits of available memory.
- At the 6th second, the program crashes. The sticks have 0 and 4 bits available respectively.

我的解法：
就照著題意寫
```c++
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int sec = 1;
        while (memory1>=sec || memory2>=sec){
            if (memory2>memory1){
                memory2 -= sec;
            }else{
                memory1 -= sec;
            }
            sec++;
        }
        vector<int> ans = {sec, memory1, memory2};
        return ans;
    }
};
```
