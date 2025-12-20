class Solution:
    def minCost(self, a: List[int], b: List[int], k: int) -> int:
        ans = sum([abs(x-y) for x,y in zip(a, b)])
        a.sort()
        b.sort()
        c = sum([abs(x-y) for x,y in zip(a,b)]) + k
        return min(ans, c)

