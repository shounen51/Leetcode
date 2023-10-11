#include <iostream>
#include <vector>

using namespace std;
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
int main(){
    Solution s = Solution();
    vector<vector<int>> score = {{10,6,9,1},{7,5,11,2},{4,8,3,15}};
    s.sortTheStudents(score, 3);
    std::cout << "Sorted array: ";
    for (vector<int> scores: score){
        for (int element : scores) {
            std::cout << element << ' ';
        }
    }
    std::cout << std::endl;
    return 0;
}
