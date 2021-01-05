class node(int):
    def __init__(self,x):
        super().__init__()
        self.height = 0
    def set_height(self, h):
        self.height = h

class height(int):
    def __init__(self, h):
        super().__init__()
        self.val = 0
    def set_val(self, x):
        self.val = x

class Solution:
    def power(self, x):
        if x%2 == 0:
            return node(x/2)
        else:
            return node(3*x+1)

    def getKth(self, lo: int, hi: int, k: int):
        num_list = [node(i) for i in range(lo,hi+1)]
        node_list = []
        count_list = []
        for index, num in enumerate(num_list):
            temp_node_list = [num]
            h = 0
            while not num == 1:
                if num in node_list:
                    i = node_list.index(num)
                    h += node_list[i].height
                    num = 1
                else:
                    num = self.power(num)
                    temp_node_list.append(num)
                    h += 1
            for i, n in enumerate(temp_node_list):
                n.set_height(h - i)
            node_list += temp_node_list
            _h = height(h)
            _h.set_val(num_list[index])
            count_list.append(_h)
        count_list.sort()
        return count_list[k-1].val
s = Solution()
print(s.getKth(12,15,2))



