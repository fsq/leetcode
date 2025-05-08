class Solution:
    def maxScore(self, n: int, k: int, stayScore: List[List[int]], travelScore: List[List[int]]) -> int:
        f = [0] * n
        for t in range(k):
            g = [0] * n
            for i in range(n):
                for j in range(n):
                    if i != j:
                        g[j] = max(g[j], f[i] + travelScore[i][j])
                    else:
                        g[j] = max(g[j], f[i] + stayScore[t][i])
            f = g
        return max(f)