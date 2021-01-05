class Solution {
public:
	string addStrings(string num1, string num2) {
		int carry = 0;
		int i = 1;
		string ans = "";
		while ((int)num1.length() - i >= 0 || (int)num2.length() - i >= 0 || carry > 0) {
			int a, b;
			if ((int)num1.length() - i >= 0) {
				a = num1.at(num1.length() - i) - 48;
			}
			else {
				a = 0;
			}
			if ((int)num2.length() - i >= 0) {
				b = num2.at(num2.length() - i) - 48;
			}
			else {
				b = 0;
			}
			ans += to_string((a + b + carry) % 10);
			carry = (a + b + carry) / 10;
			i++;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};