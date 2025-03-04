# Definition of commonBits API.
# def commonBits(num: int) -> int:

class Solution:
    def findNumber(self) -> int:
        ans = 0
        for i in range(30):
            x = commonBits(1 << i)
            y = commonBits(1 << i)
            if x > y:
                ans |= 1 << i;
        return ans