class Solution:
    def equalSubstring(self, s: str, t: str, cost: int) -> int:
        a = [abs(ord(x)-ord(y)) for x,y in zip(s, t)]
        l = x = ans = 0 
        for r in range(len(s)):
            x += a[r]
            while x > cost:
                x, l = x-a[l], l+1
            ans = max(ans, r-l+1)
        return ans