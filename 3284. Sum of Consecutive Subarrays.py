class Solution:
    def getSum(self, a: List[int]) -> int:
        ans = 0
        i = 0
        M = int(1e9 + 7)
        while i < len(a):
            tot = a[i]
            ans += tot
            j = i + 1
            d = a[j] - a[i] if j<len(a) else 0
            if abs(d) == 1:
                while j < len(a) and a[j]-a[j-1]==d:
                    tot = tot + a[j] * (j-i+1)
                    ans = (ans + tot) % M
                    j += 1
            if j == i + 1:
                i = j
            else:
                j -= 1
                ans -= a[j]
                i = j
        return ans % M
