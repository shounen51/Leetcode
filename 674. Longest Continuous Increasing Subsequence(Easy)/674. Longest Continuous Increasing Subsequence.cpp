class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int ans = 1;
        int combo = 1;
        int n = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > n) {
                combo += 1;
                if (combo > ans) {
                    ans = combo;
                }
            }
            else {
                combo = 1;
            }
            n = nums[i];
        }
        return ans;
    }
};