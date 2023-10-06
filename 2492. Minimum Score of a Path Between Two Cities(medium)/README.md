給一個n代表有n座城市，給一個二維陣列roads代表城市之間的雙向道路之間的長度

比方說 n = 2, roads = [[1,2,10]] 
代表總共有兩座城市，第一和第二座城市之間有一條道路連接，長度是10

回傳從第1座城市走到第n座城市的路線中，最短的其中兩座城市的路線(不是總路徑長度，而是路徑中的其中兩座)

※必定有一條路能夠從1走到n
※路徑可以重複走
※路徑走到1或n也可以繼續走
※並非每一座城市之間都有路徑可以抵達

範例:
> Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
> Output: 2
從1走到n的路線是 1>2>1>3>4，其中1>2的距離是2所以答案是2
所以可以走廢路去蹭最短的路徑

> Input: n = 4, roads = [[1,4,100],[2,3,1]]
> Output: 100
雖然2>3的最短路徑是1，但是這條路徑沒有辦法和1或4相連，所以蹭不到

我的想法：
根本不用管路是怎麼走的，只要找出所有1走的到的城市中最短的路就好，所以只要一直for roads去找出所有相連的城市，這裡面最短的路就是答案
```python
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
```
code解析
一開始只能確定1和n是相連的，所以connected_city只有1和n，接著for roads，慢慢擴大確定相連的城市，但根據roads的排序不同，我們可能會錯過其實有相連的城市，比方說roads=[[2,3,1],[1,3,10],[1,4,10]]，如果只進行一次for迴圈就會錯過[2,3,1]這條路其實和1,4是有相連的，所以每當我們找到新的相連城市就要再進行一次for，也就是RECHECK要改成true的部分

他用城市和距離來表達這個題目，可是求的不是起點和目的地之間的最短路徑而是路徑中隨意兩座城市，要求最短卻又可以隨意走廢路，不太懂求這個最短的物理意義是甚麼，感覺應該要用別的方式來表達

我的解法似乎是最快的最省的，速度贏100%記憶體贏96%