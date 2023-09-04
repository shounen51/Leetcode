#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
    void deeper(string s, int score, int add, int count, int n){
        if (add == 1){
            s+=")";
        }else{
            s+="(";
        }
        score += add;
        if (count==n){
            ans.push_back(s);
            return;
        }
        count++;
        if((score-1)+(n-count)>=0){
            deeper(s, score, -1, count, n);
        }
        if(score+1<=0){
            deeper(s, score, 1, count, n);
        }
    }
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        ans = {};
        string s;
        deeper(s, 0, -1, 1, n*2);
        return ans;
    }