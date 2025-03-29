class Solution:
    def maximumSubarrayXor(self, a: List[int], queries: List[List[int]]) -> List[int]:
        n = len(a)
        f = [[0]*n for _ in range(n)]
        g = [[0]*n for _ in range(n)]

        for i in range(n):
            f[i][i] = g[i][i] = a[i]
        for l in range(2, n+1):
            i, j = 0, l - 1
            while j < n:
                g[i][j] = g[i][j-1] ^ g[i+1][j]
                f[i][j] = max(f[i][j-1], f[i+1][j], g[i][j])
                i += 1
                j += 1
        return [f[i][j] for i, j in queries]