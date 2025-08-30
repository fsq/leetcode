class Solution:
    def getLargestOutlier(self, nums: List[int]) -> int:
        f = collections.Counter(nums)
        tot = sum(nums)
        ans = -inf
        for out in f.keys():
            rem = tot - out
            if rem & 1:
                continue
            half = rem // 2
            if f.get(half, 0) >= 1 + (1 if out==half else 0):
                ans = max(ans, out)
        return ans
