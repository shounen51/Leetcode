import bisect
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
if __name__ == "__main__":
    s = Solution()
    print(s.minOperations([47,50,97,58,87,72,41,63,41,51,17,21,7,100,69,66,79,92,84,9,57,26,26,28,83,38], [3]))