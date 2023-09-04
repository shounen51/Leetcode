class Solution:
    def rankTeams(self, votes):
        base = len(votes)+1
        scores = {}
        for char in sorted(votes[0]):
            scores[char] = 0
        for vote in votes:
            for rank, char in enumerate(vote[::-1]):
                scores[char] += pow(base, rank)
        sorted_team = sorted(scores.keys(), key=scores.get, reverse=True)
        ans = "".join(sorted_team)
        return ans
S = Solution()
print(S.rankTeams(["BCA","CAB","CBA","ABC","ACB","BAC"]))
