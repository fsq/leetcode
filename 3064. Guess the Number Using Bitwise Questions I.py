# Definition of commonSetBits API.
# def commonSetBits(num: int) -> int:

class Solution:
    def findNumber(self) -> int:
        ans = 0
        for i in range(30):
            ans |= (commonSetBits(1<<i)) << i
        return ans