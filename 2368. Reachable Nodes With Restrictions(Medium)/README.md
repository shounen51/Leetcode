給一顆有n節點的樹，還有長度為n-1的edges用來表示哪些點有連線，還有一個restricted的array代表禁止通行的點
回傳從起點開始最多可以連線到多少點
起點必定為0
樹一定成立(沒有沒連線的葉子沒有環)
這題沒有圖比較難懂

Example 1:
Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
Output: 4
Explanation: The diagram above shows the tree.
We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node.

Example 2:
Input: n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
Output: 3
Explanation: The diagram above shows the tree.
We have that [0,5,6] are the only nodes that can be reached from node 0 without visiting a restricted node.

我的想法：
起初我的想法是一直回圈跑edges，然後從0開始連線把整條路抓出來，直到某一次回圈沒有再發現新的可以走的點就是結束
```c++
class Solution {
private:
    bool inVector(int node, vector<int>& vec){
        auto it = find(vec.begin(), vec.end(), node);
        return it != vec.end();
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        // set<int> restrictedSet(restricted.begin(), restricted.end());
        int ans = 1;
        vector<int> safeNode = {0};
        while (safeNode.size()>0){
            int checkNode = safeNode[0];
            safeNode.erase(safeNode.begin());
            vector<vector<int>> keepEdges;
            for (vector<int> edge : edges){
                int safeNodeToCheck = -1;
                bool unsafe = false;
                for (int node : edge){
                    if (node == checkNode) safeNodeToCheck = edge[0]==node?edge[1]:edge[0];
                    if (inVector(node, restricted)) unsafe = true;
                }
                if (safeNodeToCheck != -1){
                    if (unsafe) continue;
                    ans++;
                    safeNode.push_back(safeNodeToCheck);
                }
                else keepEdges.push_back(edge);
            }
            edges = keepEdges;
        }
        return ans;
    }
};
```
但這個寫法在倒數第二個case超時，代表我的方法是行不通的
雖然在遍歷的過程中我有不斷地減少edges的數量，但還是無法避免的有一直重複遍歷到相同的元素，所以問題出在查詢的這個動作太多餘了
所以其實應該先把edges轉換成unordered_map，達到最快速的查詢
其中還有restricted也是不斷的在進行查詢動作，一樣轉換成unordered_map
這樣就夠快了
```c++
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
```

