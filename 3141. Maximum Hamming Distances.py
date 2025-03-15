import queue
class Solution:
    def maxHammingDistances(self, nums: List[int], m: int) -> List[int]:
        q = queue.Queue()
        dis = [None] * (1<<m)
        for i, x in enumerate(nums):
            dis[x] = 0
            q.put([x, 0])
        
        while not q.empty():
            x, d = q.get()
            for i in range(m):
                y = x ^ (1<<i)
                if dis[y] == None:
                    dis[y] = d + 1
                    q.put([y, d+1])
        
        return [m - dis[(1<<m)-1 - x] for x in nums]