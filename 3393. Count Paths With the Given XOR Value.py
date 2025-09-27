class Solution:
    def countPathsWithXorValue(self, a: List[List[int]], K: int) -> int:
        n, m = len(a), len(a[0])
        M = int(1e9 + 7)
        f = [[[0]*16 for _ in range(m)] for _ in range(n)]
        f[0][0][a[0][0]] = 1
        for i in range(n):
            for j in range(m):
                for k in range(16):
                    if f[i][j][k] > 0:
                        f[i][j][k] %= M
                        if i+1<n:
                            f[i+1][j][k ^ a[i+1][j]] += f[i][j][k]
                        if j+1<m:
                            f[i][j+1][k ^ a[i][j+1]] += f[i][j][k]
        return f[n-1][m-1][K]
