#include <unordered_map>
#include <unordered_set>
#include <map>
#include <queue>

using namespace std;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, multimap<double, int>> edges_map;
        for (int i=0; i<n; i++){
            edges_map[i] = multimap<double, int>{};
        }
        for (int i=0; i<edges.size();i++){
            vector<int> pair = edges[i];
            edges_map[pair[0]].insert({succProb[i], pair[1]});
            edges_map[pair[1]].insert({succProb[i], pair[0]});
        }
        unordered_set<int> path;
        multimap<double, int>nextNodes({{{1.0, start_node}}});
        while (nextNodes.size()>0){
            auto probAndPair = nextNodes.rbegin();
            double prob = probAndPair->first;
            int node = probAndPair->second;
            if (node==end_node) return prob;
            path.insert(node);
            nextNodes.erase(prev(nextNodes.end()));
            for (auto edgeIt=edges_map[node].rbegin(); edgeIt != edges_map[node].rend(); edgeIt++){
                double nextProb = prob*edgeIt->first;
                int nextNode = edgeIt->second;
                auto it = path.find(nextNode);
                if (it != path.end()) continue;
                nextNodes.insert({nextProb, nextNode});
            }            
        }
        return 0;
    }
};