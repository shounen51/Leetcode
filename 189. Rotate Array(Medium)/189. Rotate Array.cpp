class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp = 0;

        if (nums.size() != 0) {
            k %= nums.size();
            for (int i = 0; i < k; i++) {
                temp = nums.back();
                nums.pop_back();
                nums.insert(nums.begin(), temp);
            }
        }
    }
};