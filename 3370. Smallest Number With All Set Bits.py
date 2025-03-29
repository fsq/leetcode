class Solution:
    def smallestNumber(self, n: int) -> int:
        x = 1
        while x < n:
            x = x << 1 | 1
        return x