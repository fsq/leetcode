class Solution:
    def maximumAmount(self, a: List[List[int]]) -> int:
        n, m = len(a), len(a[0])
        f = [[[-inf]*3 for _ in range(m)] for _ in range(n)]
        f[0][0][0] = a[0][0]
        f[0][0][1] = 0
        for i in range(n):
            for j in range(m):
                if i+j == 0:
                    continue
                for k in range(3):
                    x = f[i-1][j][k]+a[i][j] if i > 0 else -inf
                    x1 = f[i-1][j][k-1] if i>0 and k>0 else -inf
                    y = f[i][j-1][k]+a[i][j] if j > 0 else -inf
                    y1 = f[i][j-1][k-1] if j>0 and k>0 else -inf
                    f[i][j][k] = max(x, x1, y, y1)
        return max(f[n-1][m-1])
