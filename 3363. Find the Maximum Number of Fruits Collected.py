class Solution:
    def maxCollectedFruits(self, a: List[List[int]]) -> int:
        n = len(a)
        ans = 0
        for i in range(n):
            ans += a[i][i]

        @lru_cache(maxsize=None)
        def dp(x, y, stp):
            if x>=n or x<0 or y>=n or y<0 or x==y:
                return -inf
            if y < x:
                if stp == 0:
                    return a[x][y] if x==n-1 else -inf
                return max(dp(x-1, y-1, stp-1), dp(x, y-1, stp-1), 
                            dp(x+1, y-1, stp-1)) + a[x][y]
            else:
                if stp == 0:
                    return a[x][y] if y==n-1 else -inf
                return max(dp(x-1, y-1, stp-1), dp(x-1, y, stp-1), 
                            dp(x-1, y+1, stp-1)) + a[x][y]
                            
        ans += dp(n-1, n-2, n-2) + dp(n-2, n-1, n-2)
        return ans

