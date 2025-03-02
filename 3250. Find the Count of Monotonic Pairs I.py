class Solution:
    def countOfPairs(self, a: List[int]) -> int:
        mod = 10**9 + 7
        n = len(a)
        f = [[0]*51 for _ in range(n)] # f[n][a]
        for i in range(a[0]+1):
            f[0][i] = 1
        for i in range(n-1):
            for x in range(51):
                if f[i][x] > 0:
                    for next_x in range(max(x, a[i+1]+x-a[i]), a[i+1]+1):
                        f[i+1][next_x] = (f[i+1][next_x] + f[i][x]) % mod
        return sum([f[n-1][x] for x in range(51)]) % mod
