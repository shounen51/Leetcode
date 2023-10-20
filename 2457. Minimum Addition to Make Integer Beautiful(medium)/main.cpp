#include <iostream>
#include <string>
#include <sstream>

using namespace std;
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
int main(){
    Solution s = Solution();
    long long a = s.makeIntegerBeautiful(1, 1);
    cout << a << endl;
    return 0;
}