class Solution:
    def maxGoodNumber(self, nums: List[int]) -> int:
        def cmp(x, y):
            s = x + y
            t = y + x
            return 1 if s < t else -1
        a = sorted([format(x, 'b') for x in nums], key=cmp_to_key(cmp))
        return int(''.join(a), 2)