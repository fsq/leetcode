class Solution:
    def maxDistance(self, side: int, a: List[List[int]], k: int) -> int:
        for i, b in enumerate(a):
            if b[1] == 0:
                a[i] = b[0]
            elif b[1] == side:
                a[i] = 3*side - b[0]
            elif b[0] == 0:
                a[i] = 4*side - b[1]
            else:
                a[i] = side + b[1]
        a.sort()

        def ok(l):
            for start in range(len(a)-k+1):
                cur = start
                for i in range(k-1):
                    nxt = bisect_left(a, a[cur]+l, lo=cur+1)
                    if nxt == len(a):
                        return False
                    cur = nxt
                if a[cur]+l <= a[start]+4*side:
                    return True
            return False

        l, r = 1, side
        while l < r:
            mid = (l + r + 1) >> 1
            if ok(mid):
                l = mid
            else:
                r = mid - 1
        return l
