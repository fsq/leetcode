class Solution:
    def transformArray(self, nums: List[int]) -> List[int]:
        return sorted([x%2 for x in nums])