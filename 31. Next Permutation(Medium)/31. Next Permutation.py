def findsmall(nums, n):
    n = len(nums) - n - 1
    rnums = reversed(nums)
    rnums = list(rnums)
    for index, i in enumerate(rnums):
        if i < rnums[n] and index > n:
            return len(nums) - index - 1
    return -1
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        last = len(nums)-1
        changeH = -1
        changeL = 0
        while last > 0:
            __changeH = findsmall(nums, last)
            if __changeH > changeH:
                changeH = __changeH
                changeL = last
            last -= 1

        if changeL < 0:
            nums.reverse()
        else:
            nums[changeL], nums[changeH] = nums[changeH], nums[changeL]
            new = nums[changeH + 1:]
            new.sort()
            nums[changeH + 1:] = new