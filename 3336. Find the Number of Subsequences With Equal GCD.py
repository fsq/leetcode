class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        f = [[0]*201 for _ in range(201)]
        f[0][0] = 1
        M = int(1e9 + 7)
        for x in nums:
            g = [a[:] for a in f]
            for a in range(0, 201):
                for b in range(0, 201):
                    if f[a][b]:
                        t = gcd(a, x) if a > 0 else x
                        g[t][b] = (g[t][b] + f[a][b]) % M
                        t = gcd(b, x) if b > 0 else x
                        g[a][t] = (g[a][t] + f[a][b]) % M
            f = g
            
        ans = 0
        for i in range(1, 201):
            ans = (ans + f[i][i]) % M
        return ans
