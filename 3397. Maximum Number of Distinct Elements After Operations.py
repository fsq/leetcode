class Solution:
    def maxDistinctElements(self, a: List[int], k: int) -> int:
        a.sort()
        nxt = -inf
        ans = 0
        for x in a:
            if nxt > x + k:
                continue
            nxt = max(nxt + 1, x - k + 1)
            ans += 1
        return ans
