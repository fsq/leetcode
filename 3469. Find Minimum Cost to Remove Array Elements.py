class Solution:
    def minCost(self, a: List[int]) -> int:
        n = len(a)
        if n <= 2:
            return max(a)

        @lru_cache(maxsize=None)
        def dp(i, pre):
            if i==n-1:
                ans = max(a[i], pre)
            elif i==n:
                ans = pre
            else:
                x, y, z = sorted([a[i], a[i+1], pre])
                ans = dp(i+2, z) + y
                ans = min(ans, dp(i+2, x) + z)
                # Prune: pre now can only be largest/smallest value of a[:i]
                # ans = min(ans, dp(i+2, y) + z)
            return ans
        
        return dp(1, a[0])
