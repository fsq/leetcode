class Solution:
    def rob(self, a: List[int]) -> int:
        if not a: return 0
        n = len(a)
        f, g = [0]*n, [0]*n
        f[0] = a[0]
        for i in range(1, n):
            f[i] = g[i-1] + a[i]
            g[i] = max(g[i-1], f[i-1])
        return max(max(f), max(g))
        