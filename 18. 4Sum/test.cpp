#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    map<vector<int>, bool> ansMap;
    if(nums.size()<4){
        return ans;
    }
    sort(nums.begin(), nums.end());
    long long sum;
    long long temp;
    for(vector<int>::iterator it1=nums.begin(); it1!=nums.end()-3; it1++){
        for(vector<int>::iterator it2=it1+1; it2!=nums.end()-2; it2++){
            for(vector<int>::iterator it3=it2+1; it3!=nums.end()-1; it3++){
                temp = *it3;
                sum = *it1+*it2+temp;
                if (sum<target){
                    if(sum+*(nums.end()-1)<target)continue;
                }else if(sum>target){
                    if(sum+*(it3+1)>target)continue;
                }
                for(vector<int>::iterator it4=it3+1; it4!=nums.end(); it4++){
                    temp = *it4;
                    if(sum+temp==target){
                        vector<int>a = {*it1,*it2,*it3,*it4};
                        ansMap[a] = true;
                        break;
                    }
                }
            }
        }
    }
    for(const auto& pair : ansMap){
        ans.push_back(pair.first);
    }
    return ans;
}

int main(){
    vector<int> nums = {-2,-1,0,1,2};
    int target = 0;
    fourSum(nums, target);
    return 0;
}