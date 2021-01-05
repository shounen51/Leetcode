int Max(int a, int b) {
	return a > b ? a : b;
}

class Solution {
public:
	int rob(vector<int>& nums) {
		vector<int> ans;
		if (nums.size() == 0) {
			return 0;
		}
		else if (nums.size() == 1) {
			return nums[0];
		}
		else if (nums.size() == 2) {
			return Max(nums[0], nums[1]);
		}
		else {
			ans.push_back(nums[0]);
			ans.push_back(Max(nums[0], nums[1]));
			for (int i = 2; i < nums.size(); i++) {
				ans.push_back(Max(nums[i] + ans[i - 2], ans[i - 1]));
			}
			int a = 0;
			for (int i = 0; i < ans.size(); i++) {
				a = Max(a, ans[i]);
			}
			return a;
		}
	}
};