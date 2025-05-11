class Solution:
    def minTimeToReach(self, a: List[List[int]]) -> int:
        n, m = len(a), len(a[0])
        f = [[inf] * m for _ in range(n)]
        q = [[0, 0, 0]]
        dd = [[-1, 0], [1,0], [0,1], [0,-1]]
        while len(q):
            t, x, y = heappop(q)
            if t > f[x][y]:
                continue
            if (x, y) == (n-1, m-1):
                return f[x][y]
            for dx, dy in dd:
                tx, ty = x+dx, y+dy
                if 0<=tx<n and 0<=ty<m:
                    reach_t = max(t, a[tx][ty]) + 1
                    if reach_t < f[tx][ty]:
                        f[tx][ty] = reach_t
                        heappush(q, [reach_t, tx, ty])
        return f[n-1][m-1]
