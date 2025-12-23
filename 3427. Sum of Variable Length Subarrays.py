class Solution:
    def subarraySum(self, a: List[int]) -> int:
        return sum([sum(a[max(0, i-a[i]):i+1]) for i in range(len(a))])
