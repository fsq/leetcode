class Solution:
    def numberOfAlternatingGroups(self, a: List[int], k: int) -> int:
        n = len(a)
        i = n-1
        while i!=0 and a[i]!=a[(i+1) % n]:
            i -= 1
        cur = n - i
        ans = 1 if cur>=k else 0
        for i in range(1, n):
            cur = cur+1 if a[i]!=a[i-1] else 1
            if cur >= k:
                ans += 1
        return ans
        