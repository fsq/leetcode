class Solution:
    def countSubstrings(self, s: str) -> int:
        # f[i][j] = #substrings mod i == j
        f = [[0] * 10 for _ in range(10)]
        ans = 0
        for x in map(int, s):
            g = [[0]*10 for _ in range(10)]
            for i in range(1, 10):
                g[i][x % i] += 1
                for j in range(10):
                    g[i][(j*10+x) % i] += f[i][j]
            f = g
            ans += f[x][0]
        return ans
                    

