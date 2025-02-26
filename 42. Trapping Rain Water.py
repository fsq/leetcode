class Solution:
    def trap(self, a: List[int]) -> int:
        l, r, ans = 0, len(a)-1, 0
        hl, hr = 0, 0
        while l < r:
            hl = max(hl, a[l])
            hr = max(hr, a[r])
            if hl < hr:
                ans += hl - a[l]
                l += 1
            else:
                ans += hr - a[r]
                r -= 1
        return ans