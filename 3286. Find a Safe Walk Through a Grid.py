class Solution:
    def findSafeWalk(self, a: List[List[int]], health: int) -> bool:
        n, m = len(a), len(a[0])
        d = [[float('inf')]*m for _ in range(n)]
        d[0][0] = a[0][0]
        q = [[a[0][0], 0, 0]]
        while len(q):
            dis, x, y = heappop(q)
            if dis > d[x][y]:
                continue
            for dx, dy in [[0,1],[0,-1],[1,0],[-1,0]]:
                tx, ty = x+dx, y+dy
                if tx>=0 and tx<n and ty>=0 and ty<m:
                    dt = dis + a[tx][ty]
                    if dt < health and dt < d[tx][ty]:
                        d[tx][ty] = dt
                        heappush(q, [dt, tx, ty])
        return d[n-1][m-1] < health
