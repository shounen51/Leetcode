#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
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
int main(){
    Solution s = Solution();
    vector<int> nums = {1,21,3};
    int ans = s.countDistinctIntegers(nums);
    cout << ans << endl;
    return 0;
}