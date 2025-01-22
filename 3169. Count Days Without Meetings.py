class Solution:
    def countDays(self, days: int, mtg: List[List[int]]) -> int:
        mtg = sorted(mtg)
        pre = 0
        ans = 0
        for m in mtg:
            if m[0] > pre:
                ans += m[0] - pre - 1
            pre = max(pre, m[1])
        ans += days - pre
        return ans