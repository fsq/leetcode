class Solution:
    def maxValue(self, a: List[int], k: int) -> int:
        n = len(a)
        f = [[set() for _ in range(k+1)] for _ in range(n)]
        g = [[set() for _ in range(k+1)] for _ in range(n)]
        f[0][0] = {0}
        f[0][1] = {a[0]}
        g[n-1][0] = {0}
        g[n-1][1] = {a[-1]}
        for i in range(1, n):
            f[i][0] = {0}
            for j in range(1, min(k, i+1) + 1):
                f[i][j] = f[i-1][j] | {m1 | a[i] for m1 in f[i-1][j-1]}

        for i in reversed(range(0, n-1)):
            g[i][0] = {0}
            for j in range(1, min(k, n-i) + 1):
                g[i][j] = g[i+1][j] | {m1 | a[i] for m1 in g[i+1][j-1]}

        for ans in reversed(range(0, 1<<7)):
            for i in range(k-1, n-k):
                for m1 in f[i][k]:
                    if ans^m1 in g[i+1][k]:
                        return ans
        return 0
