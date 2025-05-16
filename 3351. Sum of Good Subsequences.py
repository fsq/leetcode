class Solution:
    def sumOfGoodSubsequences(self, a: List[int]) -> int:
        f = [0] * (max(a) + 1)
        g = f[:]
        M = 10**9 + 7
        for x in a:
            f[x] = (f[x] + x) % M
            g[x] += 1
            if x > 0:
                f[x] = (f[x] + g[x-1] * x + f[x-1]) % M
                g[x] = (g[x] + g[x-1]) % M
            if x+1 < len(f):
                f[x] = (f[x] + g[x+1] * x + f[x+1]) % M
                g[x] = (g[x] + g[x+1]) % M
     
        ans = 0
        for x in f:
            ans = (ans + x) % M
        return ans