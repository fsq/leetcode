class Solution:
    def orArray(self, nums: List[int]) -> List[int]:
        return [a | b for a, b in zip(nums, nums[1:])]