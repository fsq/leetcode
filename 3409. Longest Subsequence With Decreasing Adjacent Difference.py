class Solution:
    def longestSubsequence(self, a: List[int]) -> int:
        m = max(a)
        f = [[0]*(m+1) for _ in range(m+1)]
        ans = 0
        for x in reversed(a):
            for j in range(m):
                if j > 0:
                    f[x][j] = f[x][j-1]
                    if x + j <= m:
                        f[x][j] = max(f[x][j], f[x+j][j] + 1)
                    if x - j >= 1:
                        f[x][j] = max(f[x][j], f[x-j][j] + 1)
                else:
                    f[x][j] = f[x][j] + 1
                ans = max(ans, f[x][j])
        return ans
