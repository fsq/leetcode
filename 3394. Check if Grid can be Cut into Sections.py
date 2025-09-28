class Solution:
    def checkValidCuts(self, n: int, rs: List[List[int]]) -> bool:
        a = [[r[0], r[2]] for r in rs]
        b = [[r[1], r[3]] for r in rs]
        def ok(a):
            a.sort(key=lambda x: x[0])
            seg = 0
            last = -1
            for x in a:
                if x[0] >= last:
                    seg += 1
                    last = x[1]
                else:
                    last = max(last, x[1])
            return seg >= 3

        return ok(a) or ok(b)
