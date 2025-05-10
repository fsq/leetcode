class Solution:
    def maxScore(self, a: List[int]) -> int:
        ans = gcd(*a) * lcm(*a)
        for i in range(len(a)):
            b = a[:i] + a[i+1:]
            ans = max(ans, gcd(*b) * lcm(*b))
        return ans