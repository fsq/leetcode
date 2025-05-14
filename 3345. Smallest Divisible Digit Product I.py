class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        while True:
            prod = 1
            for c in str(n):
                prod *= ord(c) - ord('0')
            if prod % t == 0:
                return n
            n += 1
        return 0