class Solution:
    def minScore(self, n: int, roads: list) -> int:
        RECHECK = True
        connected_city = {1, n}
        min_path = 10000 # accroding to 1 <= distancei <= 10^4
        while RECHECK:
            recheck_roads = []
            RECHECK = False
            for road in roads:
                if road[0] in connected_city or road[1] in connected_city:
                    connected_city.add(road[0])
                    connected_city.add(road[1])
                    if road[2] < min_path:
                        min_path = road[2]
                    RECHECK = True
                else:
                    recheck_roads.append(road)
            roads = recheck_roads
        return min_path
S = Solution()
n = 6
roads = [[4,5,7468],[6,2,7173],[6,3,8365],[2,3,7674],[5,6,7852],[1,2,8547],[2,4,1885],[2,5,5192],[1,3,4065],[1,4,7357]]
print(S.minScore(n,roads))