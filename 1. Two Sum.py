class Solution:
    def twoSum(self, a: List[int], target: int) -> List[int]:
        d = {}
        for i, x in enumerate(a):
            if target-x in d:
                return [d[target-x], i]
            else:
                d[x] = i