class Solution:
    def countSubarrays(self, a: List[int]) -> int:
        ans = 0
        for i in range(len(a)-2):
            if 2*(a[i]+a[i+2]) == a[i+1]:
                ans += 1
        return ans
