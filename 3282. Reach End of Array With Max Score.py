class Solution:
    def findMaximumScore(self, a: List[int]) -> int:
        # A = (2-1)*a1 + (1-0)*a0
        # B = (2-0)*a0
        # B - A = (2-1)a0 - (2-1)a1
        # if a0 > a1, B > A

        a[-1] = float('inf')
        ans = 0
        cur = a[0]
        ind = 0
        for i, x in enumerate(a[1:], start=1):
            if x > cur:
                ans += (i-ind) * cur
                cur = x
                ind = i
        return ans