class Solution:
    def hasIncreasingSubarrays(self, nums: List[int], k: int) -> bool:
        if k == 1:
            return True
        i, j = 1, k+1
        inc1 = inc2 = 1
        while j < len(nums):
            if nums[i]>nums[i-1]:
                inc1 += 1
            else:
                inc1 = 1
            if nums[j]>nums[j-1]:
                inc2 += 1
            else:
                inc2 = 1
            if inc1>=k and inc2>=k:
                return True
            i += 1
            j += 1
        return False