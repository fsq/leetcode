class Solution:
    def maxIncreasingSubarrays(self, a: List[int]) -> int:
        prev = 0
        cur_len = ans = 1
        for i in range(1, len(a)+1):
            if i < len(a) and a[i] > a[i-1]:
                cur_len += 1
            else:
                ans = max(ans, min(cur_len, prev), cur_len//2)
                prev, cur_len = cur_len, 1
        return ans