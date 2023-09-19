#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
    char findTarget(vector<vector<char>> ss){
        int maxContinueSame = 0;
        char target;
        for(vector<char> s:ss){
            char tempTarget = *s.begin();
            int continueSame = 0;
            for(char c:s){
                if (c == tempTarget){
                    if (++continueSame > maxContinueSame){
                        maxContinueSame = continueSame;
                        target = tempTarget;
                    }
                }else{
                    break;
                }
            }
        }
        return target;
    }
    void reverseTarget(char* t){
        if(*t == '1') *t = '0';
        else *t = '1';
    }
    long long countCost(vector<char> s, char target){
        int len = s.size();
        long long cost = 0;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(c != target){
                cost += len-i;
                reverseTarget(&target);
            }
        }
        return cost;
    }
public:
    long long minimumCost(string s) {
        char target;
        vector<char> frontS;
        vector<char> backS;
        if(s.length()%2==1){
            target = *(s.begin() + ((s.length()-1)/2));
            frontS = vector<char>(s.rbegin()+(s.length()-1)/2+1, s.rend());
            backS = vector<char>(s.begin()+(s.length()-1)/2+1, s.end());
        }
        else{
            frontS = vector<char>(s.rbegin()+(s.length())/2, s.rend());
            backS = vector<char>(s.begin()+(s.length())/2, s.end());
            vector<vector<char>> ss = {frontS, backS};
            target = findTarget(ss);
        }
        long long totalCost = countCost(frontS, target) + countCost(backS, target);
        return totalCost;
    }
};
int main(){
    Solution s = Solution();
    cout << s.minimumCost("0011") << endl;
    return 0;
}
