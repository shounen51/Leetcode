給一個'0''1'組成的字串s，int minJump, maxJump
字串的開頭結尾必定是'0'
必須判斷是否能夠從開頭的0走到尾端的0，走的規則是：
1.  '0'代表可以站，'1'代表不能站
2.  走的時候用跳的，可以跳過i格，1 <= minJump <= i <= maxJump
3.  不能往回跳不能跳超過

Example 1:
Input: s = "011010", minJump = 2, maxJump = 3
Output: true
Explanation:
In the first step, move from index 0 to index 3. 
In the second step, move from index 3 to index 5.

Example 2:
Input: s = "01101110", minJump = 2, maxJump = 3
Output: false

我用了bitset來輔助運算，先將s轉換成bitset叫做binaryRoad，然後not運算改成1可以走0不能走，然後遍歷s，看到0就判斷當下這個0能不能被到達
判斷的方式是動態生一個jump範圍的mask，如果minJump=2 maxJump=4的話從當前位置往前就會是1110，表示前面那三個1的位置如果有可以站的點的話就可以跳的到當前位置，所以binaryRoad去and jump範圍之後用.none()就會知道當前位置能不能被跳到，不能的話就要把binaryRoad的當前位置改成0(不能被抵達)，用這個方式遍歷完之後看最後一個點就會知道是否可以到達
```c++
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        const int maxSize = 100000;
        int s_size = s.size();
        if (s_size < maxSize){
            s += string(maxSize-s_size,'1');
        }
        bitset<maxSize> binaryRoad(s);
        bitset<maxSize> jumpRange;
        binaryRoad = ~binaryRoad;
        for (int i=1; i<s_size; i++){
            char c = s[i];
            if (c == '0'){
                int start = max(0, i-maxJump);
                int end = max(0, i-minJump);
                jumpRange = bitset<maxSize>(string(end-start+1, '1'));
                jumpRange <<= (maxSize - i + minJump - 1);
                jumpRange = jumpRange & binaryRoad;
                if (jumpRange.none()){
                    binaryRoad.set(maxSize-i-1,0);
                }
            }
        }
        if (binaryRoad[maxSize-s_size]) return true;
        else return false;
    }
};
int main()
{
    string str = "011010";
    int minJump = 2;
    int maxJump = 3;
    Solution s = Solution();
    cout << s.canReach(str,minJump,maxJump) << endl;
    return 0;
}
```
這個方法可以求出正確答案，但是速度太慢了不會通過提交

後來看了別人的DP算法，以下解析
```c++
class Solution {
public:
    bool canReach(string s, int minJ, int maxJ) {
        int n = s.size(), pre = 0;
        vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = 1; i < n; ++i) {
            if (i >= minJ)
                pre += dp[i - minJ];
            if (i > maxJ)
                pre -= dp[i - maxJ - 1];
            dp[i] = pre > 0 && s[i] == '0';
        }
        return dp[n - 1];
    }
};
```
dp裡面放的是該點是否可以到達，初始化第一個是true其他都是false
算法的重點參數是pre，看懂pre就懂整個算法，我覺得要解釋的話應該叫做"跳躍能力的累算"
一樣是遍歷s
兩個判斷式都只是防越界，重點放在
`pre += dp[i - minJ];`
`pre -= dp[i - maxJ - 1];`
把他想像成跳躍能力的開關，如果往前看到最小跳躍距離的那格(i - minJ)是可以站的，就表示接下來的格子通通都可以跳的到，直到那格的最大跳躍距離(i - maxJ - 1)，所以開始的地方開啟(pre+=1)，結束的地方關閉(pre-=1)，因為可能在還沒關閉的時候就遇到下一個可以跳的點，所以必須用int去累算，而不是用bool開關。
如果一個點它本身是可以站的，而且算到當下的時候pre=3那表示有3個點是可以跳的到當前這個點的，但這並不重要反正可以跳的到就好
最後再參考dp的最後一個點就知道能不能到終點了
這個算法其實和我的想法是一樣的，只是他用了pre，我用了mask運算，但速度上來說是天差地遠，因為mask運算就得實際去參考跳躍範圍中的所有點，pre去算的話只需要參考最小跳躍點和最大跳躍點
