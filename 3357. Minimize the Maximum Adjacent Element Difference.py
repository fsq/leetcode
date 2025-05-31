class Solution:
    def minDifference(self, a: List[int]) -> int:
        l, r = 0, max(max(a), 0)
        for x, y in zip(a, a[1:]):
            if x!=-1 and y!=-1:
                l = max(l, abs(x-y))
        if l == r:
            return l

        adj = []
        i, j = 0, 0
        mn, mx = inf, -inf
        while i < len(a):
            if a[i] != -1:
                i += 1
                continue
            j = i
            while j<len(a) and a[j]==-1: j += 1
            pr = []
            if i > 0:
                pr.append(a[i-1])
            if j<len(a):
                pr.append(a[j])
            if len(pr)==1:
                pr.append(pr[0])
            adj.append([i+1==j, pr])
            mn = min(mn, min(pr))
            mx = max(mx, max(pr))
            i = j + 1

        def ok(pos, d):
            x, y = mn+d, mx-d

            def fit(x, a):
                return abs(x[0]-a[0])<=d and abs(x[1]-a[1])<=d

            for single, elem in adj:
                if not (fit([x, x], elem) or fit([y, y], elem)):
                    if single:
                        return False
                    if not (\
                        (fit([x, y], elem) and abs(x-y)<=d) or \
                        (fit([y, x], elem) and abs(x-y)<=d)):
                        return False
            return True

        while l < r:
            d = (l + r) // 2
            if ok(pos, d):
                r = d
            else:
                l = d + 1
        return l