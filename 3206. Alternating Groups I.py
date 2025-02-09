class Solution:
    def numberOfAlternatingGroups(self, a: List[int]) -> int:
        ans = 0
        for i in range(len(a)):
            pre = a[i-1]
            nxt = a[(i+1) % len(a)]
            if a[i]!=pre and a[i]!=nxt:
                ans += 1
        return ans