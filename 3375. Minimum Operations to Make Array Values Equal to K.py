class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        a = sorted(list(set(nums)))
        if a[0] < k:
            return -1
        return len(a) - 1 + (a[0]!=k)
