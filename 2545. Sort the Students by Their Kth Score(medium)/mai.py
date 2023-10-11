class Solution:
    def sortTheStudents(self, score: list, k: int) -> list:
        return sorted(score, key=lambda s:s[k], reverse=True)

S = Solution()
print(S.sortTheStudents([[10,6,9,1],[7,5,11,2],[4,8,3,15]], k = 2))
