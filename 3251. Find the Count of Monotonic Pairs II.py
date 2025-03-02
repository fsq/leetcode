class Solution:
    def countOfPairs(self, a: List[int]) -> int:
        mod = 10**9 + 7
        n = len(a)
        f = [[0]*1002 for _ in range(n)] # f[n][a]
        f[0][0] = 1
        f[0][a[0]+1] = -1
        for i in range(n-1):
            cur = 0
            for x in range(a[i]+1):
                cur = (f[i][x] + cur) % mod
                f[i][x] = cur
                if f[i][x] > 0:
                    l, r = max(x, a[i+1]+x-a[i]), a[i+1]
                    if l <= r:
                        f[i+1][l] += f[i][x]
                        f[i+1][r+1] -= f[i][x]

        ans, cur = 0, 0
        for i in range(a[-1]+1):
            cur = (cur + f[n-1][i]) % mod
            ans = (ans + cur) % mod
        return ans
