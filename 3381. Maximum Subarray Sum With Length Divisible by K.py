class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        r = {}
        r[0] = 0
        cur = sz = 0
        ans = -inf
        for x in nums:
            sz += 1
            cur += x
            if sz % k in r:
                ans = max(ans, cur - r[sz%k])
                r[sz%k] = min(r[sz%k], cur)
            else:
                r[sz%k] = cur
        return ans
