#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

bool compareDescending(int a, int b) {
    return a > b;
}

class Solution {
private:
    bool isSubSet(vector<int>& full, vector<int>& sub){
        unordered_set<int> fullSet(full.begin(), full.end());
        for (const auto& num : sub) {
            if (fullSet.find(num) == fullSet.end()) {
                return false;
            }
        }
        return true;
    }
public:
    int tallestBillboard(vector<int>& rods) {
        int sum = 0;
        for (auto v : rods){
            sum += v;
        }
        sort(rods.begin(), rods.end(), compareDescending);
        // reverse(rods.begin(), rods.end());
        vector<vector<vector<int>>> dp(int(sum/2), vector<vector<int>>());
        for (int i=0; i < dp.size(); i++){
            vector<int> leftRods(rods);
            for (int v : rods){
                if 
            }
        }
        
    }
};
int main(){
    vector<int> coins = {186,419,83,408};
    Solution s = Solution();
    return 0;
}