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

if __name__=="__main__":
    grid = ["\\/\\ "," /\\/"," \\/ ","/ / "]
    S = Solution()
    print(S.regionsBySlashes(grid))
