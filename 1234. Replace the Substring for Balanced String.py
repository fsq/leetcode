class Solution:
    def balancedString(self, s: str) -> int:
        count = collections.defaultdict(int)
        extra = collections.defaultdict(int)
        for c in s:
            count[c] += 1
        for c in "QWER":
            extra[c] = max(0, count[c]-len(s)//4)
            count[c] = 0
        
        ans = len(s)
        l = r = 0
        while (r < len(s)):
            count[s[r]] += 1
            while l<=r and count[s[l]] > extra[s[l]]:
                count[s[l]] -= 1
                l += 1
                
            if all(count[c]>=extra[c] for c in "QWER"):
                ans = min(ans, r-l+1)
            r += 1
        return ans
        