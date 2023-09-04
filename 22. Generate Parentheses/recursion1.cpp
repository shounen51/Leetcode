#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
    vector<string> deeper(vector<string> ans, string s, int score, int add, int count, int n){
        if (add == 1){
            s+=")";
        }else{
            s+="(";
        }
        score += add;
        if (count==n){
            ans.push_back(s);
            return ans;
        }
        count++;
        if((score-1)+(n-count)>=0){
            ans = deeper(ans, s, score, -1, count, n);
        }
        if(score+1<=0){
            ans = deeper(ans, s, score, 1, count, n);
        }
        return ans;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        ans = deeper(ans, s, 0, -1, 1, n*2);
        return ans;
    }