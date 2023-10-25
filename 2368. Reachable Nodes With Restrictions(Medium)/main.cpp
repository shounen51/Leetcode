#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {   
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int, vector<int>> connections;
        unordered_map<int, int> safeNode;
        vector<int> checkNodes = {0};
        for (int i=0; i<n; i++){
            vector<int> temp;
            connections[i] = temp;
            safeNode[i] = 0;
        }
        for (int node : restricted){
            safeNode[node] = -1;
        }
        for (vector<int> edge : edges){
            connections[edge[0]].push_back(edge[1]);
            connections[edge[1]].push_back(edge[0]);
        }
        int ans = 1;
        while(checkNodes.size()>0){
            safeNode[checkNodes[0]]=1;
            for (int node : connections[checkNodes[0]]){
                if (safeNode[node]!=0) continue;
                else{
                    checkNodes.push_back(node);                    
                    safeNode[node]=1;
                    ans++;
                }
            }
            checkNodes.erase(checkNodes.begin());
        }
        return ans;
    }
};
int main(){
    Solution s = Solution();
    vector<vector<int>> edges = {{4,1},{1,3},{1,5},{0,5},{3,6},{8,4},{5,7},{6,9},{3,2}};
    vector<int> restricted = {2,7};
    int a = s.reachableNodes(10, edges, restricted);
    cout << a << endl;
    return 0;
}