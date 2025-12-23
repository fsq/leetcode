class Solution:
    def minCost(self, n: int, cost: List[List[int]]) -> int:
        @lru_cache(maxsize=None)
        def dp(i, j, a, b):
            if i > j:
                return 0
            ans = inf
            for x in range(3):
                for y in range(3):
                    if x!=y and x!=a and y!=b:
                        ans = min(ans, dp(i+1, j-1, x, y) + cost[i][x] + cost[j][y])
            return ans
        
        return dp(0, n-1, 4, 4)
