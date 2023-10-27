這題沒辦法用文字敘述，必須得看圖
有一個n\*n的網格，但網格是沒有存在內部線的(word建立n\*n的表格之後合併成一個表格的概念)，每個網格都有可能存在斜線、反斜線或空白
給一個list[str] grid來表達這些斜線，比方說grid=[" /","/ "]
回答出n*n的網格被切成了幾個區塊

我們不可能用給的grid直接計算區塊，所以這題最重要的一點就是要想到如何用更好的方式表達出網格的狀態，必須有利於計算區塊
要記錄一個這樣的表格基本上分成兩種方向，要嘛紀錄點的狀態要嘛紀錄格子的狀態
題目給的grid算是紀錄格子的狀態，格子的狀態只有三種很好紀錄，有想到一個方法或許可以解但我沒有採用所以不確定

建立一個list[tuple(tuple(int,int),list[int])]，第一個tuple的是座標，後面的list[int]是方向(上下左右0123)，從左上角(0,0)開始，如果遇到／則紀錄((0,0),[0,2])和((0,0),[1,3])，表示目前發現有兩個區塊需要探索，一個往上往左延伸，另一個往右往下延伸，然後繼續DFS或BFS，每發現一個新區域要嘛有新的區域需要探索，要嘛就是閉合(遇到牆壁或遇到已探索的區域)，用這個方式應該也可以有解

第二種紀錄方式就是紀錄點的狀態，一個n\*n的表格會有n+1\*n+1個點，然後記錄這些點彼此相連的狀態，用BFS或DFS都可以，把點都走過一遍，如果遇到了已經走過的點就表示已經形成了一個環，一個環就表示框起了一個區域，用這個方式去計算有幾個區域

我分別實現了DFS和BFS，測試下來這題用DFS快不少，但我覺得他們應該要一樣快才對，不曉得是不是我的BFS沒寫好做了多餘的步驟
```python
import queue

class Solution:
    def __go(self, start, last):
        self.passed_node[start] = True
        nexts = self.connections[start]
        for next in nexts:
            if next==last: continue
            if not self.passed_node[next]:
                self.__go(next, start)
            else:
                self.regions+=1
        return
    
    def regionsBySlashes(self, grid: list) -> int:
        one_side_long = len(grid[0])+1
        self.connections = {}
        self.passed_node = {}
        for y in range(one_side_long):
            for x in range(one_side_long):
                self.connections[(x,y)] = []
                self.passed_node[(x,y)] = 0

        for i in range(one_side_long-1):
            self.connections[(i,0)].append((i+1,0))
            self.connections[(i+1,0)].append((i,0))
            self.connections[(0,i)].append((0,i+1))
            self.connections[(0,i+1)].append((0,i))
            self.connections[(one_side_long-1,i)].append((one_side_long-1,i+1))
            self.connections[(one_side_long-1,i+1)].append((one_side_long-1,i))
            self.connections[i,one_side_long-1].append((i+1, one_side_long-1))
            self.connections[i+1,one_side_long-1].append((i, one_side_long-1))

        for y, string in enumerate(grid):
            for x, slash in enumerate(string):
                if slash=='/':
                    self.connections[(x+1,y)].append((x,y+1))
                    self.connections[(x,y+1)].append((x+1,y))
                elif slash=="\\":
                    self.connections[(x,y)].append((x+1,y+1))
                    self.connections[(x+1,y+1)].append((x,y))

        self.regions = 0
        
        # # DFS
        # for start in self.connections:
        #     if not self.passed_node[start]:
        #         self.__go(start,(-1,-1))
        # return int(self.regions)

        # BFS
        self.search_queue = queue.Queue()
        for start in self.connections:
            if self.passed_node[start] == 0:
                self.search_queue.put((start, None))
                self.passed_node[start] = 1
            while self.search_queue.qsize() > 0:
                start, last = self.search_queue.get()
                self.passed_node[start] = 2
                nexts = self.connections[start]
                for next in nexts:
                    if next==last: continue
                    if self.passed_node[next] == 0:
                        self.search_queue.put((next, start))
                        self.passed_node[next] = 1
                    elif self.passed_node[next] == 2:
                        self.regions+=1
        return self.regions
```