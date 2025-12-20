class Solution:
    def maxAdjacentDistance(self, a: List[int]) -> int:
        return max(*[abs(x-y) for x,y in pairwise(a)], abs(a[0]-a[-1]))
