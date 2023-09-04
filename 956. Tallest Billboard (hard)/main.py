from collections import Counter
import copy

class Solution(object):
    def contains_list(self, a, b):
        counter_a = Counter(a)
        counter_b = Counter(b)
        return all(counter_a[element] >= count for element, count in counter_b.items())
    
    def tallestBillboard(self, rods:list):
        """
        :type rods: List[int]
        :rtype: int
        """
        rods.sort()
        total = sum(rods)
        dp = {}
        for i in range(1, int((total+1)/2)+1):
            dp[i] = []
            [dp[i].append([i]) for _ in range(rods.count(i))]
            remain_rods = [rod for rod in rods if rod <= i]
            for a in range(int(i/2), 0, -1):
                b = i-a
                if len(dp[a]) and len(dp[b]):
                    for combo_a in dp[a]:
                        for combo_b in dp[b]:
                            combo = combo_a + combo_b
                            if self.contains_list(remain_rods, combo):
                                [remain_rods.remove(i) for i in combo]
                                dp[i].append(combo)
        for ans in reversed(list(dp.keys())):
            if len(dp[ans]) >= 2: return ans
        return 0
class Solution2(object):
    def tallestBillboard(self, rods):
        dp = {0: 0}  

        for rod in rods:
            # Create a shallow copy of current dp table
            # to avoid modifying it while iterating over it
            curr_dp = dp.copy()

            for height in curr_dp:
                dp[height + rod] = max(dp.get(height + rod, 0), curr_dp[height])
            
                dp[abs(height - rod)] = max(dp.get(abs(height - rod), 0), curr_dp[height] + min(height, rod))

        return dp.get(0, 0)  
S = Solution2()
print(S.tallestBillboard([1,2,3,4,5,6]))
# print(S.tallestBillboard([1,2,4,8,16,32,64,128,256,512,50,50,50,150,150,150,100,100,100,123]))