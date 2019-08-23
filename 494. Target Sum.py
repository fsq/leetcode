class Solution:
    def findTargetSumWays(self, a: List[int], target: int) -> int:
        n = len(a)
        f = [dict() for i in range(n)]
        f[0][a[0]] = f[0].get(a[0], 0) + 1
        f[0][-a[0]]= f[0].get(-a[0], 0) + 1
        for i in range(1, n):
            for s, c in f[i-1].items():
                f[i][s+a[i]] = f[i].get(s+a[i], 0) + c
                f[i][s-a[i]] = f[i].get(s-a[i], 0) + c
        return f[n-1].get(target, 0)
            