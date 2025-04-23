class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: List[int]) -> int:
        def count(s):
            tot = 0
            for x in workerTimes:
                # (1+2+...+n) <= s/x => (1+n)*n <= 2s/x => n^2 + n - 2s/x <= 0
                # delta = 1 + 8s/x
                # x2 = -1+sqrt(delta)/2
                delta = 1 + 8*s / x
                n = floor((sqrt(delta)-1) / 2)
                tot += n
            return tot

        l, r = 0, int(1e16)
        while l < r:
            mid = (l + r) >> 1
            if count(mid) < mountainHeight:
                l = mid + 1
            else :
                r = mid
        return l