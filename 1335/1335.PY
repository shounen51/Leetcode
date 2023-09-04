import time
class Solution():
    def fun(self, seg, index, max):
        if seg[index] + 1 < max:
            seg[index] += 1
            for i in range(index+1, len(seg)):
                seg[i] = seg[i-1]+1
            return False, seg
        else:
            if index > 0:
                return self.fun(seg, index-1, max-1)
            else:
                return True, seg

    def minDifficulty_B(self, jobDifficulty: list, d: int):
        if len(jobDifficulty) < d:
            return -1
        elif len(jobDifficulty) == 1:
            return jobDifficulty[0]
        dp = []
        for start in range(len(jobDifficulty)):
            dp.append([0 for _ in range(start+1)])
            for end in range(start+1, len(jobDifficulty)+1):
                f = jobDifficulty[start:end]
                dp[start].append(max(f))
        ans = sum(jobDifficulty)
        seg = [i for i in range(1, d)]
        while 1:
            cut = [0] + seg + [len(jobDifficulty)]
            diff = 0
            for i in range(len(cut)-1):
                start = cut[i]
                end = cut[i+1]
                diff += dp[start][end]
            if diff < ans: ans = diff
            if len(seg)-1 < 0: break
            end, seg = self.fun(seg, len(seg)-1, len(jobDifficulty))
            if end: break
        return ans

    # def minDifficulty(self, jobDifficulty: list, d: int):
    #     if len(jobDifficulty) < d:
    #         return -1
    #     while len(jobDifficulty) > d:
    #         tops = []
    #         tops_index = []
    #         for i, job in enumerate(jobDifficulty):
    #             if len(tops) < d:
    #                 tops.append(job)
    #                 tops_index.append(i)
    #             else:
    #                 if job > min(tops):
    #                     min_index = tops.index(min(tops))
    #                     tops[min_index] = job
    #                     tops_index[min_index] = i
    #         diff = []
    #         diff_index = []
    #         for index in tops_index:
    #             left_one = jobDifficulty[index-1] if index > 0 else 0
    #             right_one = jobDifficulty[index+1] if index < len(jobDifficulty)-1 else 0
    #             if left_one > right_one:
    #                 diff.append(left_one)
    #                 diff_index.append(index-1)
    #             else:
    #                 diff.append(right_one)
    #                 diff_index.append(index+1)
    #         max_diff_index = diff.index(max(diff))
    #         if diff[max_diff_index] > tops[max_diff_index]:
    #             pop_index = tops_index[max_diff_index]
    #         else:
    #             pop_index = diff_index[max_diff_index]
    #         jobDifficulty.pop(pop_index)
    #     return sum(jobDifficulty)
s = Solution()
q1 = [380,302,102,681,863,676,243,671,651,612,162,561,394,856,601,30,6,257,921,405,716,126,158,476,889,699,668,930,139,164,641,801,480,756,797,915,275,709,161,358,461,938,914,557,121,964,315]
q2 = 10
t1 = time.time()
a = s.minDifficulty_B(q1, q2)
print(a)
print(time.time()-t1)