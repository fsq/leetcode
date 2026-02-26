class Solution:
    def longestPalindromicSubsequence(self, s: str, k: int) -> int:

        @functools.lru_cache(maxsize=None)
        def dist(a, b):
            ia = ord(a)
            ib = ord(b)
            return min((ia - ib + 26) % 26, (ib - ia + 26) % 26)
            

        @functools.lru_cache(maxsize=None)        
        def dp(l, r, k):
            if l > r:
                return 0
            if l == r:
                return 1
            if s[l] == s[r]:
                return dp(l+1, r-1, k) + 2
            else:
                ans = max(dp(l+1, r, k), dp(l, r-1, k))
                dst = dist(s[l], s[r])
                if k >= dst:
                    ans = max(ans, dp(l+1, r-1, k-dst)+2)
            return ans
        
        return dp(0, len(s)-1, k)
