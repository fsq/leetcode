class Solution:
    def largestInteger(self, nums: List[int], k: int) -> int:
        if len(nums) == 1:
            return nums[0]
        if len(nums) == k:
            return max(nums)
        c = Counter(nums)
        if k == 1:
            return max(map(lambda kv: kv[0] if kv[1]==1 else -1, c.items()))
        
        return max(nums[0] if c[nums[0]]==1 else -1, nums[-1] if c[nums[-1]]==1 else -1)
