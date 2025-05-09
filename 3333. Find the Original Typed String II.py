class Solution:
    def possibleStringCount(self, word: str, k: int) -> int:
        s = []
        m = int(1e9 + 7)
        tot = 1  # total ways to build any string
        prec = None
        for c in word:
            if c==prec:
                s[-1] += 1
            else:
                if len(s):
                    tot = (tot * s[-1]) % m
                s.append(1)
                prec = c
        tot = (tot * s[-1]) % m

        if len(s) >= k:
            return tot

        f = [0] * (k+1) # f[i] ways to build length i
        f[0] = 1
        for cnt in s[:k]:  # only consider first k-1 elements
            g = [0] * (k+1)
            for l, ways in enumerate(f):
                x, y = min(k, l+1), min(k, l+cnt+1)
                g[x] = (g[x] + ways) % m
                g[y] = (g[y] - ways + m) % m
            for i in range(1, len(g)):
                g[i] = (g[i] + g[i-1]) % m
            f = g

        return (tot - sum(f) + m) % m