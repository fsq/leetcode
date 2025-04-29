class Solution:
    def minElement(self, nums: List[int]) -> int:
        return min([sum([int(c) for c in str(x)]) for x in nums])