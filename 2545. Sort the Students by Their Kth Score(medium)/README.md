給一個二維陣列score代表全學生全科目的分數，再給一個k代表要以第k科目來排序學生，從高到低

表格或清單用不同的條件排序，或者是獨立運作的A表和B表也可以以A排B，這是實務上很常見的問題

從這題可以明顯感受到python的強大，也能感受到python的無能

因為用python寫的話我在1分鐘內用1行就寫完了
```python
class Solution:
    def sortTheStudents(self, score: List[List[int]], k: int) -> List[List[int]]:
        return sorted(score, key=lambda s:s[k], reverse=True)
```
簡單明瞭，速度是353ms，這是top5%的速度，說明大部分自己手動實現的python答案都不如內建function的快，畢竟內建sorted()裡面其實還頗複雜的

用python內建的sorted()來寫這題那就跟沒寫一樣，所以我自己實現一次，這次用C++

```c++
class Solution {
private:
    void quickSort(vector<vector<int>>& score, int k, int low, int high){
        if (low < high){
            int pivot = score[high][k];
            int i = low - 1;
            for (int j = low; j < high; j++) {
                if (score[j][k] > pivot) {
                    i++;
                    swap(score[i], score[j]);
                }
            }
            swap(score[i + 1], score[high]);
            int partitionIndex  = i + 1;
            quickSort(score, k, low, partitionIndex-1);
            quickSort(score, k, partitionIndex+1, high);
        }
    }
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        quickSort(score, k, 0, score.size()-1);
        return score;
    }
};
```
我選用的是快速排序
速度方面是top25%的49ms，沒有其他花俏技巧，樸實無華的快速排序就是python極限速度的7倍快


後來看到C++也有類似的一行寫法，原來C++內建的sort()也差不多強大，速度比我的快速排序快了7ms
```C++
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& arr, int k) {
        sort(arr.begin(),arr.end(),[k](vector<int>&a,vector<int>&b){
            return a[k]>b[k];
        });
        return arr;
    }
};
```