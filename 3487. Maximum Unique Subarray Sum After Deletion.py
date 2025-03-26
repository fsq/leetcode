class Solution:
    def maxSum(self, nums: List[int]) -> int:
        a = [x for x in nums if x > 0]
        if len(a) == 0:
            return max(nums)
        return sum(set(a))