class Solution:
    def maxProfit(self, a: List[int]) -> int:
        if not len(a): return 0
        f, g = [0]*len(a), [0]*len(a)
        g[0] = -a[0]
        for i in range(1, len(a)):
            f[i] = max(f[i-1], g[i-1]+a[i])
            g[i] = max(g[i-1], -a[i] if i<2 else f[i-2]-a[i])
        return f[-1]
        