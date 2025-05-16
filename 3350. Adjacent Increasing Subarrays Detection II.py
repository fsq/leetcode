class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:

        def valid(k):
            if k == 1:
                return True
            j = k + 1
            inc1 = inc2 = 1
            while j < len(nums):
                if nums[j-k]>nums[j-k-1]:
                    inc1 += 1
                else:
                    inc1 = 1
                if nums[j]>nums[j-1]:
                    inc2 += 1
                else:
                    inc2 = 1
                if inc1>=k and inc2>=k:
                    return True
                j += 1
            return False

        l = 1
        r = len(nums)//2
        while l < r:
            mid = (l + r + 1) >> 1
            if valid(mid):
                l = mid
            else:
                r = mid - 1
        return l