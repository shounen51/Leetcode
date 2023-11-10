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
