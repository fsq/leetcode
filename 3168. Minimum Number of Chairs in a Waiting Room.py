class Solution:
    def minimumChairs(self, s: str) -> int:
        cur, ans = 0, 0
        for c in s:
            if c == 'E':
                cur += 1
            else:
                cur -= 1
            ans = max(ans, cur)
        return ans