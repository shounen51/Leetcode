給兩個正整數陣列nums, queries，回傳正整數陣列ans
你只能夠對nums重複進行一種操作：將nums裡的正整數+1或-1
ans[i]等於讓nums裡的數字全部同等於queries裡的第i個數字所需要的最小操作次數

Input: nums = [3,1,6,8], queries = [1,5]
Output: [14,10]
3-1 + 1-1 + 6-1 + 8-1 = 14
5-3 + 5-1 + 6-5 + 8-5 = 10

我的想法：
看到題目第一個想法就是兩個for迴圈然後絕對值加總，與其說這是解法不如說這就是答案的定義，隨便提交看看果不其然運算時間太長
```python
class Solution:
    def minOperations(self, nums: list, queries: list):
        ans = []
        for target in queries:
            a = 0
            for number in nums:
                a += abs(number-target)
            ans.append(a)
        return ans
```
那麼就是要想辦法加速了
一開始先想想看別的計算方式，把全部數值先加起來之後再扣掉target*len(nums)也可以計算出距離，不過這只適用於target比nums全部都小或大的做法，所以要分開兩次計算
為了得到全部小於或大於target的陣列我需要先把nums排序，然後看target在nums中排第幾個，分成小的一堆大的一堆之後就可以用公式去計算前後兩堆的總距離，不過這個算法似乎並沒有比較快，依舊在同一個testcase中運算過久
```python
class Solution:    
    def minOperations(self, nums: list, queries: list):
        nums = sorted(nums)
        ans = []
        for target in queries:
            front = bisect.bisect_right(nums, target)
            front_dis_sum = target*front - sum(nums[0:front])
            back = len(nums) - front
            back_dis_sum = sum(nums[front:front+back]) - target*back
            ans.append(front_dis_sum + back_dis_sum)
        return ans
```
不過以這個算法為基礎看到了下一步加速的方式，這樣會慢是因為sum的部分一直重複運算了，只要能夠解決這個重複的部分就可以再加速了
sum的計算是從某個位置切一刀之後前半後半的總和，所以只會有len(nums)個組合，把這個部分先行計算完的話sum的部分就和queries的長度無關了，而且計算的速度也會變快，因為不再是用call好幾次sum()的方式，而是用累加就好
所以要計算的sum有兩個，一個是前半一個是後半，當確定一刀切在哪個位置的時候就去提取該位置的兩個sum就好
不過其實只要sum一次就足夠了，一個sum裡面理論上有包含另一個的資訊，可以透過計算得到，最終的寫法就是
```python
class Solution:
    def minOperations(self, nums: list, queries: list):
        nums = sorted(nums)
        temp = 0
        zig = [0]
        for n in nums:
            temp += n
            zig.append(temp)
        ans = []
        for target in queries:
            front = bisect.bisect_right(nums, target)
            front_dis_sum = target*front - zig[front]
            back = len(nums) - front
            back_dis_sum = zig[-1] - zig[front] - target*back
            ans.append(front_dis_sum + back_dis_sum)
        return ans
```
加總的陣列前面偷塞一個0可以解決計算的時候target在最第一個導致前半的加總要另外寫判斷式改成0的問題，寫起來比較漂亮

