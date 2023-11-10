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
