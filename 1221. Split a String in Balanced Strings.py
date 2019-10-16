class Solution:
    def balancedStringSplit(self, s: str) -> int:
        a, ans = 0, 0
        for c in s:
            a += 1 if c=='L' else -1
            if a==0:
                ans += 1
        return ans