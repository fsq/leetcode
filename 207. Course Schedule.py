class Solution:
    def canFinish(self, n: int, edge: List[List[int]]) -> bool:
        e, ind = [[] for _ in range(n)], [0] * n
        
        for x,y in edge:
            e[y].append(x)
            ind[x] += 1
            
        q = collections.deque(x for x in range(n) if ind[x]==0)
        while len(q):
            x = q.popleft()
            for y in e[x]:
                ind[y] -= 1
                if ind[y]==0:
                    q.append(y)
        
        return max(ind)==0
        
        
            