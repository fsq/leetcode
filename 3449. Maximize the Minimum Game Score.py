class Solution:
    def maxScore(self, a: List[int], m: int) -> int:
        if m < len(a):
            return 0
        l, r = min(a), min(a)*int(ceil(m/2))

        def ok(t):
            budget = m
            i = now = nxt = 0
            while i<len(a) and budget >= 1:
                now += a[i]
                budget -= 1
                if now < t:
                    need = (t-now+a[i]-1)//a[i]
                    budget -= need * 2
                    if budget < 0:
                        return False
                    if i+1 < len(a):
                        nxt = need * a[i+1]
                i += 1
                now = nxt
                nxt = 0
            return i==len(a) or (i==len(a)-1 and now>=t)

        while l < r:
            mid = (l + r + 1) >> 1
            if ok(mid):
                l = mid
            else:
                r = mid - 1
        return l
