class Solution:
    def maximumTotalSum(self, a: List[int]) -> int:
        a.sort(reverse=True)
        ans = cur = a[0]
        for h in a[1:]:
            cur = min(h, cur-1)
            if cur == 0:
                return -1
            ans += cur
        return ans