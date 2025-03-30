class Solution:
    def maxPossibleScore(self, a: List[int], d: int) -> int:
        a.sort()

        # min diff between all pairs >=l
        def score_ge(l):
            cur = a[0]
            for x in a[1:]:
                y = max(x, min(x+d, cur+l))
                if cur+l > y:
                    return False
                cur = y
            return True
                
        l, r = 0, a[-1]+d-a[0]
        while l < r:
            mid = (l + r + 1) >> 1
            if score_ge(mid):
                l = mid
            else:
                r = mid - 1
        return l