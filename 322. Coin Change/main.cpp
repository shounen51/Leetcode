#include <iostream>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;

class Solution {
private:
    map<int, int> calculatedCoins;
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        int bestAns = -1;
        auto it = calculatedCoins.find(amount);
        if (it != calculatedCoins.end()) return calculatedCoins[amount];
        for (int c: coins){
            if (amount >= c){
                int Mamount = amount - c;
                if (Mamount == 0) return 1;
                int ans = coinChange(coins, Mamount);
                if (ans != -1){
                    ans++;
                    if (bestAns == -1) bestAns = ans;
                    else if (ans < bestAns) bestAns = ans;
                }
            }
        }
        calculatedCoins[amount] = bestAns;
        return bestAns;
    }
};
int main(){
    vector<int> coins = {186,419,83,408};
    int amount = 6249;
    Solution s = Solution();
    int ans = s.coinChange(coins, amount);
    cout << ans;
    return 0;
}