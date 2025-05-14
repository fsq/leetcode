class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        nums.sort()
        i = j = ans = 0
        cnt = Counter(nums)

        for x in nums:
            while nums[i] < x-k: i += 1
            while j<len(nums) and nums[j] <= x+k: j += 1
            ans = max(ans, min(cnt[x]+numOperations, j - i))
        
        j = 0
        for i in range(len(nums)):
            while j < len(nums) and nums[j] <= nums[i]+k+k:
                j += 1
            ans = max(ans, min(numOperations, j - i))
        
        return ans
        