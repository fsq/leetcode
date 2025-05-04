class Solution:
    def maxRemovals(self, s: str, t: str, indx: List[int]) -> int:
        n, m = len(s), len(t)
        ind = set(indx)
        f = [[-inf]*(m+1) for _ in range(n+1)]
        f[0][0] = 0
        for i in range(n):
            f[i+1][0] = f[i][0]
            f[i+1][0] += 1 if i in ind else 0
            for j in range(min(i+1, m)):
                # no removal
                f[i+1][j+1] = f[i][j] if s[i]==t[j] else f[i][j+1]
                # remove
                if i in ind:
                    f[i+1][j+1] = max(f[i+1][j+1], f[i][j+1] + 1)
        return f[n][m]