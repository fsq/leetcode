class Solution:

    def maximize_score(self, f, g, pos, cur, msk):
        if f[cur][msk] != -1:
            return f[cur][msk]
        if msk == 0:
            return 0
        for i in range(len(pos)):
            if msk & (1 << i):
                f[cur][msk] = max(f[cur][msk], \
                    self.dis[cur][i] + Solution.minimize_score(self, f,g,pos,i, msk ^ (1<<i)))
        return f[cur][msk]
    
    def minimize_score(self, f, g, pos, cur, msk):
        if g[cur][msk] != float('inf'):
            return g[cur][msk]
        if msk == 0:
            return 0
        for i in range(len(pos)):
            if msk & (1 << i):
                g[cur][msk] = min(g[cur][msk], \
                    self.dis[cur][i] + Solution.maximize_score(self, f,g,pos,i, msk ^ (1<<i)))
        return g[cur][msk]

    def bfs(pos):
        delta = [[2,1],[2,-1],[1,2],[1,-2],[-1,2],[-1,-2],[-2,-1],[-2,1]]
        def helper(x, y):
            d = [[-1]*50 for _ in range(50)]
            d[x][y] = 0
            q = deque()
            q.append([x, y])
            while len(q):
                x, y = q.popleft()
                for dx,dy in delta:
                    tx, ty = x + dx, y + dy
                    if tx>=0 and tx<50 and ty>=0 and ty<50 and d[tx][ty] == -1:
                        d[tx][ty] = d[x][y] + 1
                        q.append([tx, ty])
            return d

        ans = []
        for i in range(len(pos)):
            dis = helper(*pos[i])
            ans.append([dis[x][y] for x,y in pos])
        return ans

    def maxMoves(self, kx: int, ky: int, pos: List[List[int]]) -> int:
        pos.insert(0, [kx, ky])
        n = len(pos)
        self.dis = Solution.bfs(pos)
        # f[i][m] maximize move at i, remain m
        f = [[-1] * (1<<n) for _ in range(n)] 
        # minimize ..
        g = [[float('inf')] * (1<<n) for _ in range(n)] 

        return Solution.maximize_score(self, f, g, pos, 0, (1<<n)-2)
