class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        m = {0:1}
        s = ans = 0
        for x in nums:
            s += x
            ans += m.get(s-k, 0)
            m[s] = m.get(s, 0) + 1
        return ans