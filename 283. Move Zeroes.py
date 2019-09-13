class Solution:
    def moveZeroes(self, a: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l = 0
        for r in range(len(a)):
            if a[r] != 0:
                a[l], a[r] = a[r], a[l]
                l += 1