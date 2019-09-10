class Solution:
    def maximumSum(self, a: List[int]) -> int:
        n = len(a)
        f, g = [0]*n, [0]*n
        f[0], g[0] = -sys.maxsize, a[0]
        for i in range(1, n):
            g[i] = max(g[i-1]+a[i], a[i])
            f[i] = max(g[i-1], f[i-1]+a[i])
        return max(f+g)